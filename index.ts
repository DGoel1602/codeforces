import { mkdir } from "node:fs/promises";

const handle = Bun.argv[2];

if (!handle) {
  console.error("Usage: bun run index.ts <codeforces-handle>");
  process.exit(1);
}

type CodeforcesResponse<T> =
  | {
      status: "OK";
      result: T;
    }
  | {
      status: "FAILED";
      comment: string;
    };

type CodeforcesProblem = {
  contestId?: number;
  index: string;
  name: string;
  rating?: number;
  tags: string[];
};

type CodeforcesSubmission = {
  id: number;
  creationTimeSeconds: number;
  contestId?: number;
  programmingLanguage: string;
  verdict?: string;
  problem: CodeforcesProblem;
};

type PlannedSubmission = {
  path: string;
  exists: boolean;
  submission: CodeforcesSubmission;
};

const commitSplitThreshold = 20;
const readmePath = "solutions/README.md";

function problemKey(submission: CodeforcesSubmission): string | null {
  const contestId = submission.problem.contestId ?? submission.contestId;

  if (!contestId) {
    return null;
  }

  return `${contestId}/${submission.problem.index.toLowerCase()}`;
}

function extensionForLanguage(language: string): string | null {
  const normalized = language.toLowerCase();

  if (normalized.includes("c++")) {
    return "cpp";
  }

  if (normalized.includes("python") || normalized.includes("pypy")) {
    return "py";
  }

  if (normalized.startsWith("java ")) {
    return "java";
  }

  if (normalized.includes("gnu c") || normalized === "c") {
    return "c";
  }

  return null;
}

function solutionPath(submission: CodeforcesSubmission): string | null {
  const contestId = submission.problem.contestId ?? submission.contestId;

  if (!contestId) {
    return null;
  }

  const extension = extensionForLanguage(submission.programmingLanguage);

  if (!extension) {
    return null;
  }

  return `solutions/${contestId}/${submission.problem.index.toLowerCase()}.${extension}`;
}

function submissionSourceUrl(submission: CodeforcesSubmission): string {
  const contestId = submission.problem.contestId ?? submission.contestId;

  if (!contestId) {
    throw new Error(`Submission ${submission.id} has no contest id`);
  }

  return `https://codeforces.com/problemset/submission/${contestId}/${submission.id}`;
}

function decodeHtml(value: string): string {
  const namedEntities: Record<string, string> = {
    amp: "&",
    gt: ">",
    lt: "<",
    quot: '"',
    apos: "'",
    nbsp: " ",
  };

  return value.replaceAll(
    /&(#x[0-9a-f]+|#\d+|[a-z]+);/gi,
    (entity, body: string) => {
      const normalized = body.toLowerCase();

      if (normalized.startsWith("#x")) {
        return String.fromCodePoint(Number.parseInt(normalized.slice(2), 16));
      }

      if (normalized.startsWith("#")) {
        return String.fromCodePoint(Number.parseInt(normalized.slice(1), 10));
      }

      return namedEntities[normalized] ?? entity;
    },
  );
}

function extractSource(html: string, submissionId: number): string {
  const match = html.match(
    /<pre[^>]*id="program-source-text"[^>]*>([\s\S]*?)<\/pre>/,
  );

  if (!match) {
    throw new Error(`Could not find source for submission ${submissionId}`);
  }

  return `${decodeHtml(match[1]).replace(/\r\n/g, "\n").trimEnd()}\n`;
}

async function fetchSubmissions(handle: string): Promise<CodeforcesSubmission[]> {
  const url = new URL("https://codeforces.com/api/user.status");
  url.searchParams.set("handle", handle);

  const response = await fetch(url);

  if (!response.ok) {
    throw new Error(`Codeforces returned HTTP ${response.status}`);
  }

  const body = (await response.json()) as CodeforcesResponse<
    CodeforcesSubmission[]
  >;

  if (body.status === "FAILED") {
    throw new Error(body.comment);
  }

  return body.result;
}

async function fetchSubmissionSource(
  submission: CodeforcesSubmission,
): Promise<string> {
  const response = await fetch(submissionSourceUrl(submission));

  if (!response.ok) {
    throw new Error(
      `Codeforces returned HTTP ${response.status} for submission ${submission.id}`,
    );
  }

  return extractSource(await response.text(), submission.id);
}

function finalAcceptedSubmissions(
  submissions: CodeforcesSubmission[],
): CodeforcesSubmission[] {
  const byProblem = new Map<string, CodeforcesSubmission>();

  for (const submission of submissions) {
    if (submission.verdict !== "OK") {
      continue;
    }

    const key = problemKey(submission);

    if (!key || byProblem.has(key)) {
      continue;
    }

    byProblem.set(key, submission);
  }

  return [...byProblem.values()].sort((left, right) => {
    const leftContest = left.problem.contestId ?? left.contestId ?? 0;
    const rightContest = right.problem.contestId ?? right.contestId ?? 0;

    if (leftContest !== rightContest) {
      return leftContest - rightContest;
    }

    return left.problem.index.localeCompare(right.problem.index, undefined, {
      numeric: true,
    });
  });
}

async function writeSubmission(item: PlannedSubmission): Promise<void> {
  const source = await fetchSubmissionSource(item.submission);
  const directory = item.path.slice(0, item.path.lastIndexOf("/"));

  await mkdir(directory, { recursive: true });
  await Bun.write(item.path, source);
}

function readmeRow(submission: CodeforcesSubmission): string {
  const contestId = submission.problem.contestId ?? submission.contestId;
  const problem = `${submission.problem.index}. ${submission.problem.name}`;
  const rating = submission.problem.rating?.toString() ?? "";
  const topics = submission.problem.tags.join(", ");

  return `| ${contestId} | ${problem} | ${rating} | ${topics} |`;
}

async function updateSolutionsReadme(items: PlannedSubmission[]): Promise<void> {
  const headerLine = "| Contest | Problem | Rating | Topics |";
  const separatorLine = "| --- | --- | --- | --- |";
  const header = `${headerLine}\n${separatorLine}`;
  const existing = await Bun.file(readmePath).text().catch(() => header);
  const rows = new Set(
    existing
      .split("\n")
      .filter(
        (line) =>
          line.startsWith("| ") &&
          !line.includes("---") &&
          line !== headerLine,
      ),
  );

  for (const item of items) {
    rows.add(readmeRow(item.submission));
  }

  const sortedRows = [...rows].sort((left, right) =>
    left.localeCompare(right, undefined, { numeric: true }),
  );

  await Bun.write(readmePath, `${header}\n${sortedRows.join("\n")}\n`);
}

async function runGit(args: string[]): Promise<void> {
  const process = Bun.spawn(["git", ...args], {
    stderr: "pipe",
    stdout: "pipe",
  });
  const [stdout, stderr, exitCode] = await Promise.all([
    new Response(process.stdout).text(),
    new Response(process.stderr).text(),
    process.exited,
  ]);

  if (exitCode !== 0) {
    const output = [stdout.trim(), stderr.trim()].filter(Boolean).join("\n");
    throw new Error(`git ${args.join(" ")} failed:\n${output}`);
  }
}

async function commitPaths(message: string, paths: string[]): Promise<void> {
  await runGit(["add", ...paths]);
  await runGit(["commit", "-m", message]);
}

function commitMessageFor(item: PlannedSubmission): string {
  const contestId = item.submission.problem.contestId ?? item.submission.contestId;
  const index = item.submission.problem.index.toUpperCase();

  return `Add Codeforces ${contestId}${index}`;
}

async function writeAndCommitSubmissions(
  items: PlannedSubmission[],
): Promise<void> {
  if (items.length === 0) {
    return;
  }

  if (items.length > commitSplitThreshold) {
    for (const item of items) {
      await writeSubmission(item);
    }

    await updateSolutionsReadme(items);
    await commitPaths(`Add ${items.length} Codeforces submissions`, [
      ...items.map((item) => item.path),
      readmePath,
    ]);
    return;
  }

  for (const item of items) {
    await writeSubmission(item);
    await updateSolutionsReadme([item]);
    await commitPaths(commitMessageFor(item), [item.path, readmePath]);
  }
}

const submissions = await fetchSubmissions(handle);
const accepted = finalAcceptedSubmissions(submissions);
const planned = await Promise.all(
  accepted.map(async (submission) => {
    const path = solutionPath(submission);

    if (!path) {
      return null;
    }

    return {
      path,
      exists: await Bun.file(path).exists(),
      submission,
    };
  }),
);
const validPlanned = planned.filter((item) => item !== null);
const missing = validPlanned.filter((item) => !item.exists);
const commitMode =
  missing.length > commitSplitThreshold
    ? "one batch commit"
    : "one commit per submission";

console.log(`Found ${accepted.length} final AC submissions for ${handle}.`);
console.log(
  `${validPlanned.length} use C++, Java, C, or Python and can be saved.`,
);
console.log(`${missing.length} submissions are not in solutions/ yet.`);
console.log(`Commit mode for this run: ${commitMode}.`);

for (const item of missing.slice(0, 10)) {
  const { submission } = item;
  const contestId = submission.problem.contestId ?? submission.contestId;
  const rating = submission.problem.rating ?? "unrated";
  const tags = submission.problem.tags.join(", ") || "no tags";

  console.log(
    `${item.path} <- submission ${submission.id}: ${contestId}/${submission.problem.index.toLowerCase()} - ${submission.problem.name} (${rating}) [${submission.programmingLanguage}; ${tags}]`,
  );
}

if (missing.length > 10) {
  console.log(`...and ${missing.length - 10} more.`);
}

if (missing.length > 0) {
  await writeAndCommitSubmissions(missing);
  console.log(`Wrote and committed ${missing.length} submissions.`);
} else {
  console.log("No new submissions to write.");
}
