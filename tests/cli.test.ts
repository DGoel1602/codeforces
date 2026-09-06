import { afterEach, expect, test } from "bun:test";
import { createHash } from "node:crypto";
import { mkdtemp, rm } from "node:fs/promises";
import { tmpdir } from "node:os";
import { join, resolve } from "node:path";

const project = resolve(import.meta.dir, "..");
const directories: string[] = [];

afterEach(async () => {
  await Promise.all(
    directories
      .splice(0)
      .map((path) => rm(path, { recursive: true, force: true })),
  );
});

function git(cwd: string, ...args: string[]): string {
  const result = Bun.spawnSync(["git", ...args], {
    cwd,
    env: {
      ...process.env,
      GIT_CONFIG_GLOBAL: "/dev/null",
      GIT_CONFIG_NOSYSTEM: "1",
    },
  });
  if (result.exitCode !== 0) throw new Error(result.stderr.toString());
  return result.stdout.toString().trim();
}

async function workspace(): Promise<string> {
  const cwd = await mkdtemp(join(tmpdir(), "codeforce-push-test-"));
  directories.push(cwd);
  git(cwd, "init", "-q");
  git(cwd, "config", "user.name", "Test");
  git(cwd, "config", "user.email", "test@example.invalid");
  git(cwd, "commit", "--allow-empty", "-qm", "Initial");
  await Bun.write(
    join(cwd, "mock-api.ts"),
    `
    globalThis.fetch = async (url) => {
      await Bun.write("request.txt", String(url));
      const body = process.env.TEST_API_BODY
        ? JSON.parse(process.env.TEST_API_BODY) : await Bun.file("response.json").json();
      return Response.json(body, { status: Number(process.env.TEST_HTTP_STATUS || 200) });
    };
  `,
  );
  return cwd;
}

async function run(
  cwd: string,
  script: string,
  result: unknown,
  args: string[] = ["tester"],
  env: Record<string, string> = {},
) {
  await Bun.write(
    join(cwd, "response.json"),
    JSON.stringify({ status: "OK", result }),
  );
  const child = Bun.spawn(
    [
      process.execPath,
      "--no-env-file",
      "--preload",
      join(cwd, "mock-api.ts"),
      join(project, script),
      ...args,
    ],
    {
      cwd,
      env: {
        ...process.env,
        CF_API_KEY: "",
        CF_API_SECRET: "",
        GIT_CONFIG_GLOBAL: "/dev/null",
        GIT_CONFIG_NOSYSTEM: "1",
        ...env,
      },
      stdout: "pipe",
      stderr: "pipe",
    },
  );
  const [stdout, stderr, code] = await Promise.all([
    new Response(child.stdout).text(),
    new Response(child.stderr).text(),
    child.exited,
  ]);
  return { stdout, stderr, code };
}

function submission(
  id: number,
  contestId = 100,
  index = "A",
  language = "GNU C++17",
) {
  return {
    id,
    creationTimeSeconds: id,
    contestId,
    programmingLanguage: language,
    verdict: "OK",
    problem: { contestId, index, name: "Example", rating: 800, tags: ["math"] },
    source: `// submission ${id}\r\n\r\n`,
  };
}

test("archives the latest accepted solution per problem, normalizes sources, and keeps existing files", async () => {
  const cwd = await workspace();
  const submissions = [
    submission(10),
    submission(9),
    {
      ...submission(8, 100, "B", "PyPy 3"),
      source: undefined,
      sourceBase64: Buffer.from("print(1)\r\n").toString("base64"),
    },
    submission(7, 100, "C", "Java 21"),
    submission(6, 100, "D", "GNU C11"),
    submission(5, 100, "E", "Kotlin"),
    { ...submission(4, 100, "F"), verdict: "WRONG_ANSWER" },
    submission(3, 100, "E"),
  ];
  await Bun.write(join(cwd, "solutions/100/c.java"), "keep this\n");
  const result = await run(cwd, "index.ts", submissions);
  expect(result.code, result.stderr).toBe(0);
  expect(await Bun.file(join(cwd, "solutions/100/a.cpp")).text()).toBe(
    "// submission 10\n",
  );
  expect(await Bun.file(join(cwd, "solutions/100/b.py")).text()).toBe(
    "print(1)\n",
  );
  expect(await Bun.file(join(cwd, "solutions/100/c.java")).text()).toBe(
    "keep this\n",
  );
  expect(await Bun.file(join(cwd, "solutions/100/e.cpp")).exists()).toBe(false);
  expect(git(cwd, "log", "--format=%s").split("\n")).toEqual([
    "Add Codeforces 100D",
    "Add Codeforces 100B",
    "Add Codeforces 100A",
    "Initial",
  ]);
  const repeated = await run(cwd, "index.ts", submissions);
  expect(repeated.code, repeated.stderr).toBe(0);
  expect(git(cwd, "rev-list", "--count", "HEAD")).toBe("4");
  expect(await Bun.file(join(cwd, "solutions/README.md")).text()).toContain(
    "| 800 | 4 |",
  );
});

test.each([20, 21])(
  "keeps the commit threshold at twenty (%i missing submissions)",
  async (count) => {
    const cwd = await workspace();
    const result = await run(
      cwd,
      "index.ts",
      Array.from({ length: count }, (_, i) => submission(i + 1, i + 100)),
    );
    expect(result.code, result.stderr).toBe(0);
    expect(git(cwd, "rev-list", "--count", "HEAD")).toBe(
      count === 20 ? "21" : "2",
    );
    if (count === 21) {
      expect(git(cwd, "log", "--format=%s").split("\n")).toEqual([
        "Add 21 Codeforces submissions",
        "Initial",
      ]);
      expect(
        git(cwd, "show", "--format=", "--name-only", "HEAD").split("\n"),
      ).toHaveLength(22);
    }
  },
);

test("archive commits leave unrelated staged changes staged", async () => {
  const cwd = await workspace();
  await Bun.write(join(cwd, "notes.txt"), "unrelated work\n");
  git(cwd, "add", "notes.txt");
  const result = await run(cwd, "index.ts", [submission(1)]);
  expect(result.code, result.stderr).toBe(0);
  expect(git(cwd, "show", "--format=", "--name-only", "HEAD")).not.toContain(
    "notes.txt",
  );
  expect(git(cwd, "diff", "--cached", "--name-only")).toBe("notes.txt");
});

test("README refresh preserves escaped pipes and names containing dashes", async () => {
  const cwd = await workspace();
  const rows =
    "| 1 | A. Bitwise a \\| b | 800 | math |\n| 2 | B. A---B | 900 | implementation |\n";
  await Bun.write(join(cwd, "solutions/README.md"), rows);
  for (let i = 0; i < 2; i++) {
    const result = await run(cwd, "index.ts", []);
    expect(result.code, result.stderr).toBe(0);
    expect(await Bun.file(join(cwd, "solutions/README.md")).text()).toContain(
      rows,
    );
  }
});

test("missing source fails before any solutions are written or committed", async () => {
  const cwd = await workspace();
  const result = await run(cwd, "index.ts", [
    submission(2),
    { ...submission(1, 100, "B"), source: undefined },
  ]);
  expect(result.code).toBe(1);
  expect(result.stderr).toContain("did not include source");
  expect(git(cwd, "rev-list", "--count", "HEAD")).toBe("1");
  expect(await Bun.file(join(cwd, "solutions/100/a.cpp")).exists()).toBe(false);
});

test("watch establishes a baseline, notifies only on change, and keeps its state format", async () => {
  const cwd = await workspace();
  const args = [
    "tester",
    "--once",
    "--state",
    "state/rating.json",
    "--notify-command",
    'echo "$CF_HANDLE $CF_OLD_RATING $CF_NEW_RATING $CF_RATING_DELTA" > notification.txt',
  ];
  for (const rating of [1200, 1200, 1250]) {
    const result = await run(
      cwd,
      "watch-rating.ts",
      [{ handle: "tester", rating }],
      args,
    );
    expect(result.code, result.stderr).toBe(0);
    expect(await Bun.file(join(cwd, "notification.txt")).exists()).toBe(
      rating === 1250,
    );
  }
  expect(await Bun.file(join(cwd, "notification.txt")).text()).toBe(
    "tester 1200 1250 +50\n",
  );
  const state = await Bun.file(join(cwd, "state/rating.json")).json();
  expect(state).toEqual({
    handle: "tester",
    rating: 1250,
    checkedAt: expect.any(String),
  });
  expect(Number.isNaN(Date.parse(state.checkedAt))).toBe(false);
});

test("a failed notification command leaves the previous rating available for retry", async () => {
  const cwd = await workspace();
  const state = {
    handle: "tester",
    rating: null,
    checkedAt: "2026-01-01T00:00:00Z",
  };
  await Bun.write(
    join(cwd, ".codeforces-rating-state.json"),
    JSON.stringify(state),
  );
  const result = await run(
    cwd,
    "watch-rating.ts",
    [{ handle: "tester", rating: 1200 }],
    ["tester", "--once", "--notify-command", "exit 7"],
  );
  expect(result.code).toBe(1);
  expect(
    await Bun.file(join(cwd, ".codeforces-rating-state.json")).json(),
  ).toEqual(state);
});

test("a missing desktop notifier falls back to the terminal and saves the new rating", async () => {
  const cwd = await workspace();
  await Bun.write(
    join(cwd, ".codeforces-rating-state.json"),
    JSON.stringify({
      handle: "tester",
      rating: 1200,
      checkedAt: "2026-01-01T00:00:00Z",
    }),
  );
  const result = await run(
    cwd,
    "watch-rating.ts",
    [{ handle: "tester", rating: 1250 }],
    ["tester", "--once"],
    { PATH: cwd },
  );
  expect(result.code, result.stderr).toBe(0);
  expect(result.stdout).toContain("Desktop notification failed");
  expect(
    (await Bun.file(join(cwd, ".codeforces-rating-state.json")).json()).rating,
  ).toBe(1250);
});

test("signs archive requests with the supplied key and keeps rating requests public", async () => {
  const cwd = await workspace();
  const env = { CF_API_KEY: "test-key", CF_API_SECRET: "test-secret" };
  const result = await run(cwd, "index.ts", [], ["tester"], env);
  expect(result.code, result.stderr).toBe(0);
  const url = new URL(await Bun.file(join(cwd, "request.txt")).text());
  const signature = url.searchParams.get("apiSig")!;
  url.searchParams.delete("apiSig");
  expect(url.pathname).toBe("/api/user.status");
  expect(url.searchParams.get("apiKey")).toBe(env.CF_API_KEY);
  expect(url.searchParams.get("includeSources")).toBe("true");
  expect(url.searchParams.get("handle")).toBe("tester");
  expect(
    Math.abs(Number(url.searchParams.get("time")) - Date.now() / 1000),
  ).toBeLessThan(5);
  url.searchParams.sort();
  const expected = createHash("sha512")
    .update(
      `${signature.slice(0, 6)}/user.status?${url.searchParams}#${env.CF_API_SECRET}`,
    )
    .digest("hex");
  expect(signature.slice(6)).toBe(expected);
  const watched = await run(
    cwd,
    "watch-rating.ts",
    [{ handle: "tester" }],
    ["tester", "--once"],
    env,
  );
  expect(watched.code, watched.stderr).toBe(0);
  expect(await Bun.file(join(cwd, "request.txt")).text()).toBe(
    "https://codeforces.com/api/user.info?handles=tester",
  );
});

test("HTTP failures, API errors, and malformed submissions do not write solutions", async () => {
  const cwd = await workspace();
  const failures = [
    { body: null, status: "503", message: "HTTP 503" },
    {
      body: { status: "FAILED", comment: "Call limit exceeded" },
      status: "200",
      message: "Call limit exceeded",
    },
    {
      body: { status: "OK", result: null },
      status: "200",
      message: "invalid response",
    },
    {
      body: { status: "OK", result: [submission(1, 100, "../escape")] },
      status: "200",
      message: "invalid submission",
    },
  ];
  for (const { body, status, message } of failures) {
    const result = await run(cwd, "index.ts", [], ["tester"], {
      TEST_API_BODY: JSON.stringify(body),
      TEST_HTTP_STATUS: status,
    });
    expect(result.code).toBe(1);
    expect(result.stderr).toContain(message);
    expect(await Bun.file(join(cwd, "solutions/README.md")).exists()).toBe(
      false,
    );
  }
  expect(git(cwd, "rev-list", "--count", "HEAD")).toBe("1");
});

test("invalid saved state is reported and left intact", async () => {
  const cwd = await workspace();
  const path = join(cwd, ".codeforces-rating-state.json");
  for (const contents of [
    "{broken",
    "{}",
    '{"handle":"tester","rating":"1200","checkedAt":"2026-01-01"}',
  ]) {
    await Bun.write(path, contents);
    const result = await run(
      cwd,
      "watch-rating.ts",
      [{ handle: "tester", rating: 1250 }],
      ["tester", "--once"],
    );
    expect(result.code).toBe(1);
    expect(result.stderr).toContain("rating state");
    expect(await Bun.file(path).text()).toBe(contents);
  }
});

test("an invalid API rating does not replace the saved rating", async () => {
  const cwd = await workspace();
  const path = join(cwd, ".codeforces-rating-state.json");
  const contents = '{"handle":"tester","rating":1200,"checkedAt":"2026-01-01"}';
  await Bun.write(path, contents);
  for (const users of [[], [{}], [{ handle: "tester", rating: "1250" }]]) {
    const result = await run(cwd, "watch-rating.ts", users, [
      "tester",
      "--once",
    ]);
    expect(result.code).toBe(1);
    expect(await Bun.file(path).text()).toBe(contents);
  }
});

test("watch handles unrated transitions and starts a fresh baseline for a different handle", async () => {
  const cwd = await workspace();
  const args = [
    "tester",
    "--once",
    "--notify-command",
    'echo "$CF_OLD_RATING,$CF_NEW_RATING,$CF_RATING_DELTA"',
  ];
  await run(cwd, "watch-rating.ts", [{ handle: "tester" }], args);
  const rated = await run(
    cwd,
    "watch-rating.ts",
    [{ handle: "tester", rating: 1200 }],
    args,
  );
  expect(rated.code, rated.stderr).toBe(0);
  expect(rated.stdout).toContain("unrated,1200,");
  const unrated = await run(
    cwd,
    "watch-rating.ts",
    [{ handle: "tester" }],
    args,
  );
  expect(unrated.code, unrated.stderr).toBe(0);
  expect(unrated.stdout).toContain("1200,unrated,");
  const other = await run(
    cwd,
    "watch-rating.ts",
    [{ handle: "other", rating: 900 }],
    ["other", "--once", "--notify-command", "exit 7"],
  );
  expect(other.code, other.stderr).toBe(0);
  expect(other.stdout).toContain("Starting rating watch for other");
});

test("watch rejects invalid arguments before contacting Codeforces", async () => {
  const cwd = await workspace();
  for (const args of [
    [],
    ["tester", "--interval", "0"],
    ["tester", "--interval", "2147484"],
    ["tester", "--interval", "1.5"],
    ["tester", "--state"],
    ["tester", "--wat"],
  ]) {
    const result = await run(cwd, "watch-rating.ts", [], args);
    expect(result.code).toBe(1);
    expect(await Bun.file(join(cwd, "request.txt")).exists()).toBe(false);
  }
  expect((await run(cwd, "watch-rating.ts", [], ["--help"])).code).toBe(0);
});

test("the existing archive README survives a refresh byte for byte", async () => {
  const cwd = await workspace();
  const existing = await Bun.file(join(project, "solutions/README.md")).text();
  await Bun.write(join(cwd, "solutions/README.md"), existing);
  const result = await run(cwd, "index.ts", []);
  expect(result.code, result.stderr).toBe(0);
  expect(await Bun.file(join(cwd, "solutions/README.md")).text()).toBe(
    existing,
  );
});
