import { mkdir } from "node:fs/promises";
import { dirname } from "node:path";

type CodeforcesResponse<T> =
  | {
      status: "OK";
      result: T;
    }
  | {
      status: "FAILED";
      comment: string;
    };

type CodeforcesUser = {
  handle: string;
  rating?: number;
  maxRating?: number;
  rank?: string;
  maxRank?: string;
};

type RatingState = {
  handle: string;
  rating: number | null;
  checkedAt: string;
};

type WatchOptions = {
  handle: string;
  intervalMs: number;
  statePath: string;
  once: boolean;
  notifyCommand?: string;
};

const defaultIntervalMs = 10 * 60 * 1000;
const defaultStatePath = ".codeforces-rating-state.json";

function usage(): string {
  return [
    "Usage: bun run watch-rating.ts <codeforces-handle> [options]",
    "",
    "Options:",
    "  --interval <seconds>       Seconds between checks. Default: 600",
    "  --state <path>             State file path. Default: .codeforces-rating-state.json",
    "  --once                     Check once, notify on change, then exit",
    "  --notify-command <command> Run a shell command when the rating changes",
    "",
    "Notification command environment:",
    "  CF_HANDLE, CF_OLD_RATING, CF_NEW_RATING, CF_RATING_DELTA",
  ].join("\n");
}

function parseArgs(argv: string[]): WatchOptions {
  const handle = argv[0];

  if (!handle || handle === "--help" || handle === "-h") {
    console.error(usage());
    process.exit(handle ? 0 : 1);
  }

  let intervalMs = defaultIntervalMs;
  let statePath = defaultStatePath;
  let once = false;
  let notifyCommand: string | undefined;

  for (let index = 1; index < argv.length; index += 1) {
    const arg = argv[index];

    if (arg === "--once") {
      once = true;
      continue;
    }

    if (arg === "--interval") {
      const value = argv[index + 1];
      index += 1;

      if (!value || !/^\d+$/.test(value)) {
        throw new Error("--interval must be followed by a positive number of seconds");
      }

      intervalMs = Number(value) * 1000;

      if (intervalMs <= 0) {
        throw new Error("--interval must be greater than zero");
      }

      continue;
    }

    if (arg === "--state") {
      const value = argv[index + 1];
      index += 1;

      if (!value) {
        throw new Error("--state must be followed by a file path");
      }

      statePath = value;
      continue;
    }

    if (arg === "--notify-command") {
      const value = argv[index + 1];
      index += 1;

      if (!value) {
        throw new Error("--notify-command must be followed by a command");
      }

      notifyCommand = value;
      continue;
    }

    throw new Error(`Unknown option: ${arg}`);
  }

  return {
    handle,
    intervalMs,
    statePath,
    once,
    notifyCommand,
  };
}

async function fetchUser(handle: string): Promise<CodeforcesUser> {
  const url = new URL("https://codeforces.com/api/user.info");
  url.searchParams.set("handles", handle);

  const response = await fetch(url);

  if (!response.ok) {
    throw new Error(`Codeforces returned HTTP ${response.status}`);
  }

  const body = (await response.json()) as CodeforcesResponse<CodeforcesUser[]>;

  if (body.status === "FAILED") {
    throw new Error(body.comment);
  }

  const user = body.result[0];

  if (!user) {
    throw new Error(`Codeforces did not return a user for "${handle}"`);
  }

  return user;
}

async function readState(path: string): Promise<RatingState | null> {
  const file = Bun.file(path);

  if (!(await file.exists())) {
    return null;
  }

  return (await file.json()) as RatingState;
}

async function writeState(path: string, state: RatingState): Promise<void> {
  const directory = dirname(path);

  if (directory !== ".") {
    await mkdir(directory, { recursive: true });
  }

  await Bun.write(path, `${JSON.stringify(state, null, 2)}\n`);
}

function ratingLabel(rating: number | null): string {
  return rating === null ? "unrated" : rating.toString();
}

function ratingDelta(oldRating: number | null, newRating: number | null): string {
  if (oldRating === null || newRating === null) {
    return "";
  }

  const delta = newRating - oldRating;
  return delta > 0 ? `+${delta}` : delta.toString();
}

async function runCommand(
  command: string,
  env: Record<string, string>,
): Promise<void> {
  const child = Bun.spawn(["sh", "-c", command], {
    env: {
      ...Bun.env,
      ...env,
    },
    stderr: "pipe",
    stdout: "pipe",
  });
  const [stdout, stderr, exitCode] = await Promise.all([
    new Response(child.stdout).text(),
    new Response(child.stderr).text(),
    child.exited,
  ]);

  if (stdout.trim()) {
    console.log(stdout.trim());
  }

  if (exitCode !== 0) {
    const output = [stderr.trim(), stdout.trim()].filter(Boolean).join("\n");
    throw new Error(`Notification command failed:\n${output}`);
  }
}

async function sendDesktopNotification(title: string, message: string): Promise<boolean> {
  const commands =
    process.platform === "darwin"
      ? [
          [
            "osascript",
            "-e",
            `display notification ${JSON.stringify(message)} with title ${JSON.stringify(title)}`,
          ],
        ]
      : [["notify-send", title, message]];

  for (const command of commands) {
    const child = Bun.spawn(command, {
      stderr: "pipe",
      stdout: "pipe",
    });
    const exitCode = await child.exited;

    if (exitCode === 0) {
      return true;
    }
  }

  return false;
}

async function notifyRatingChange(
  options: WatchOptions,
  oldRating: number | null,
  newRating: number | null,
): Promise<void> {
  const delta = ratingDelta(oldRating, newRating);
  const message = `${options.handle}: ${ratingLabel(oldRating)} -> ${ratingLabel(newRating)}${
    delta ? ` (${delta})` : ""
  }`;
  const env = {
    CF_HANDLE: options.handle,
    CF_OLD_RATING: ratingLabel(oldRating),
    CF_NEW_RATING: ratingLabel(newRating),
    CF_RATING_DELTA: delta,
  };

  console.log(`\u0007Rating changed: ${message}`);

  if (options.notifyCommand) {
    await runCommand(options.notifyCommand, env);
    return;
  }

  const notified = await sendDesktopNotification("Codeforces rating changed", message);

  if (!notified) {
    console.log(
      "Desktop notification failed. Install notify-send, use macOS osascript, or pass --notify-command.",
    );
  }
}

async function checkRating(options: WatchOptions): Promise<void> {
  const previousState = await readState(options.statePath);
  const user = await fetchUser(options.handle);
  const rating = user.rating ?? null;
  const checkedAt = new Date().toISOString();

  if (
    previousState &&
    previousState.handle === options.handle &&
    previousState.rating !== rating
  ) {
    await notifyRatingChange(options, previousState.rating, rating);
  } else if (!previousState || previousState.handle !== options.handle) {
    console.log(
      `Starting rating watch for ${options.handle}; current rating is ${ratingLabel(rating)}.`,
    );
  } else {
    console.log(`${checkedAt} ${options.handle}: ${ratingLabel(rating)} unchanged.`);
  }

  await writeState(options.statePath, {
    handle: options.handle,
    rating,
    checkedAt,
  });
}

function sleep(ms: number): Promise<void> {
  return new Promise((resolve) => setTimeout(resolve, ms));
}

const options = parseArgs(Bun.argv.slice(2));

while (true) {
  let failed = false;

  try {
    await checkRating(options);
  } catch (error) {
    failed = true;
    const message = error instanceof Error ? error.message : String(error);
    console.error(`${new Date().toISOString()} ${message}`);
  }

  if (options.once) {
    if (failed) {
      process.exit(1);
    }

    break;
  }

  await sleep(options.intervalMs);
}
