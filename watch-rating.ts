import { mkdir, rename, rm } from "node:fs/promises";
import { dirname } from "node:path";
import { parseArgs } from "node:util";
import { fetchRating } from "./codeforces";

type RatingState = { handle: string; rating: number | null; checkedAt: string };
type WatchOptions = {
  handle: string;
  intervalMs: number;
  statePath: string;
  once: boolean;
  notifyCommand?: string;
};

const usage = `Usage: bun run watch-rating.ts <codeforces-handle> [options]

Options:
  --interval <seconds>       Seconds between checks. Default: 600
  --state <path>             State file path. Default: .codeforces-rating-state.json
  --once                     Check once, notify on change, then exit
  --notify-command <command> Run a shell command when the rating changes
  --help, -h                 Show this help

Notification command environment:
  CF_HANDLE, CF_OLD_RATING, CF_NEW_RATING, CF_RATING_DELTA`;

async function main(args: string[]): Promise<void> {
  const options = parseWatchOptions(args);
  if (!options) return;

  while (true) {
    let failed = false;
    try {
      await checkRating(options);
    } catch (error) {
      failed = true;
      console.error(
        `${new Date().toISOString()} ${error instanceof Error ? error.message : String(error)}`,
      );
    }
    if (options.once) {
      process.exitCode = failed ? 1 : 0;
      return;
    }
    await Bun.sleep(options.intervalMs);
  }
}

function parseWatchOptions(args: string[]): WatchOptions | null {
  const { values, positionals } = parseArgs({
    args,
    allowPositionals: true,
    options: {
      interval: { type: "string", default: "600" },
      state: { type: "string", default: ".codeforces-rating-state.json" },
      once: { type: "boolean", default: false },
      "notify-command": { type: "string" },
      help: { type: "boolean", short: "h" },
    },
  });
  if (values.help) {
    console.error(usage);
    return null;
  }
  if (positionals.length !== 1 || !positionals[0]) throw new Error(usage);
  const intervalMs = Number(values.interval) * 1000;
  if (
    !/^\d+$/.test(values.interval) ||
    !Number.isSafeInteger(intervalMs) ||
    intervalMs <= 0 ||
    intervalMs > 2_147_483_647
  ) {
    throw new Error("--interval must be a whole number of seconds between 1 and 2147483");
  }
  if (!values.state) throw new Error("--state must be followed by a file path");
  if (values["notify-command"] === "")
    throw new Error("--notify-command must be followed by a command");
  return {
    handle: positionals[0],
    intervalMs,
    statePath: values.state,
    once: values.once,
    notifyCommand: values["notify-command"],
  };
}

async function checkRating(options: WatchOptions): Promise<void> {
  const previous = await readState(options.statePath);
  const rating = await fetchRating(options.handle);
  const next = { handle: options.handle, rating, checkedAt: new Date().toISOString() };

  if (!previous || previous.handle !== next.handle) {
    console.log(
      `Starting rating watch for ${next.handle}; current rating is ${ratingLabel(rating)}.`,
    );
  } else if (previous.rating !== rating) {
    await notifyRatingChange(next.handle, previous.rating, rating, options.notifyCommand);
  } else {
    console.log(`${next.checkedAt} ${next.handle}: ${ratingLabel(rating)} unchanged.`);
  }

  // A failed custom command leaves the previous rating intact for the next check.
  await writeState(options.statePath, next);
}

async function readState(path: string): Promise<RatingState | null> {
  let state;
  try {
    state = await Bun.file(path).json();
  } catch (error) {
    if ((error as NodeJS.ErrnoException).code === "ENOENT") return null;
    throw new Error(
      `Cannot read rating state ${path}: ${error instanceof Error ? error.message : String(error)}`,
    );
  }
  if (
    !state ||
    typeof state.handle !== "string" ||
    (state.rating !== null && !Number.isSafeInteger(state.rating)) ||
    typeof state.checkedAt !== "string" ||
    Number.isNaN(Date.parse(state.checkedAt))
  ) {
    throw new Error(`Invalid rating state in ${path}; expected handle, rating, and checkedAt`);
  }
  return state;
}

async function writeState(path: string, state: RatingState): Promise<void> {
  await mkdir(dirname(path), { recursive: true });
  const temporary = `${path}.${process.pid}.tmp`;
  try {
    await Bun.write(temporary, `${JSON.stringify(state, null, 2)}\n`);
    await rename(temporary, path);
  } finally {
    await rm(temporary, { force: true });
  }
}

function ratingLabel(rating: number | null): string {
  return rating === null ? "unrated" : rating.toString();
}

async function notifyRatingChange(
  handle: string,
  oldRating: number | null,
  newRating: number | null,
  command?: string,
): Promise<void> {
  let delta = "";
  if (oldRating !== null && newRating !== null) {
    const difference = newRating - oldRating;
    delta = difference > 0 ? `+${difference}` : difference.toString();
  }
  const message = `${handle}: ${ratingLabel(oldRating)} -> ${ratingLabel(newRating)}${delta ? ` (${delta})` : ""}`;
  console.log(`\u0007Rating changed: ${message}`);

  if (command) {
    await runNotificationCommand(command, {
      CF_HANDLE: handle,
      CF_OLD_RATING: ratingLabel(oldRating),
      CF_NEW_RATING: ratingLabel(newRating),
      CF_RATING_DELTA: delta,
    });
  } else if (!(await sendDesktopNotification("Codeforces rating changed", message))) {
    console.log(
      "Desktop notification failed. Install notify-send, use macOS osascript, or pass --notify-command.",
    );
  }
}

async function runNotificationCommand(command: string, env: Record<string, string>): Promise<void> {
  const child = Bun.spawn(["sh", "-c", command], {
    env: { ...Bun.env, ...env },
    stdout: "pipe",
    stderr: "pipe",
  });
  const [stdout, stderr, exitCode] = await Promise.all([
    new Response(child.stdout).text(),
    new Response(child.stderr).text(),
    child.exited,
  ]);
  if (stdout.trim()) console.log(stdout.trim());
  if (exitCode !== 0) {
    const output = [stderr.trim(), stdout.trim()].filter(Boolean).join("\n");
    throw new Error(`Notification command failed (exit ${exitCode}):\n${output}`);
  }
}

async function sendDesktopNotification(title: string, message: string): Promise<boolean> {
  const command =
    process.platform === "darwin"
      ? [
          "osascript",
          "-e",
          `display notification ${JSON.stringify(message)} with title ${JSON.stringify(title)}`,
        ]
      : ["notify-send", title, message];
  try {
    const child = Bun.spawn(command, { stdout: "ignore", stderr: "ignore" });
    return (await child.exited) === 0;
  } catch {
    return false;
  }
}

if (import.meta.main) {
  try {
    await main(Bun.argv.slice(2));
  } catch (error) {
    console.error(error instanceof Error ? error.message : String(error));
    process.exitCode = 1;
  }
}
