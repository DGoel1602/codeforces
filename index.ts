import { mkdir } from "node:fs/promises";
import { createHash } from "node:crypto";
import { Buffer } from "node:buffer";

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
  source?: string;
  sourceBase64?: string;
};

type PlannedSubmission = {
  path: string;
  exists: boolean;
  submission: CodeforcesSubmission;
};

type FetchedSubmission = PlannedSubmission & {
  source: string;
};

type ReadmeProblem = {
  contest: string;
  problem: string;
  rating: string;
  topics: string;
};

const commitSplitThreshold = 20;
const readmePath = "solutions/README.md";
const codeforcesApiKey = Bun.env.CF_API_KEY;
const codeforcesApiSecret = Bun.env.CF_API_SECRET;

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

async function fetchSubmissions(handle: string): Promise<CodeforcesSubmission[]> {
  const url = codeforcesApiUrl("user.status", {
    handle,
    ...(codeforcesApiKey && codeforcesApiSecret
      ? { includeSources: "true" }
      : {}),
  });

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

function codeforcesApiUrl(
  method: string,
  params: Record<string, string>,
): URL {
  const url = new URL(`https://codeforces.com/api/${method}`);

  if (!codeforcesApiKey || !codeforcesApiSecret) {
    for (const [key, value] of Object.entries(params)) {
      url.searchParams.set(key, value);
    }

    return url;
  }

  const signedParams: Record<string, string> = {
    ...params,
    apiKey: codeforcesApiKey,
    time: Math.floor(Date.now() / 1000).toString(),
  };
  const sortedParams = Object.entries(signedParams).sort(
    ([leftKey, leftValue], [rightKey, rightValue]) =>
      leftKey === rightKey
        ? leftValue.localeCompare(rightValue)
        : leftKey.localeCompare(rightKey),
  );
  const query = new URLSearchParams(sortedParams).toString();
  const rand = Math.random().toString(36).slice(2, 8).padEnd(6, "0");
  const hash = createHash("sha512")
    .update(`${rand}/${method}?${query}#${codeforcesApiSecret}`)
    .digest("hex");

  for (const [key, value] of sortedParams) {
    url.searchParams.set(key, value);
  }

  url.searchParams.set("apiSig", `${rand}${hash}`);

  return url;
}

function submissionSource(submission: CodeforcesSubmission): string {
  const source =
    submission.source ??
    (submission.sourceBase64
      ? Buffer.from(submission.sourceBase64, "base64").toString("utf8")
      : undefined);

  if (!source) {
    throw new Error(
      `Submission ${submission.id} did not include source. Set CF_API_KEY and CF_API_SECRET for the Codeforces account "${handle}", then rerun.`,
    );
  }

  return `${source.replace(/\r\n/g, "\n").trimEnd()}\n`;
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

async function fetchPlannedSubmission(
  item: PlannedSubmission,
): Promise<FetchedSubmission> {
  return {
    ...item,
    source: submissionSource(item.submission),
  };
}

async function writeSubmission(item: FetchedSubmission): Promise<void> {
  const directory = item.path.slice(0, item.path.lastIndexOf("/"));

  await mkdir(directory, { recursive: true });
  await Bun.write(item.path, item.source);
}

function readmeProblemFromSubmission(
  submission: CodeforcesSubmission,
): ReadmeProblem {
  const contestId = submission.problem.contestId ?? submission.contestId;

  return {
    contest: contestId?.toString() ?? "",
    problem: `${submission.problem.index}. ${submission.problem.name}`,
    rating: submission.problem.rating?.toString() ?? "",
    topics: submission.problem.tags.join(", "),
  };
}

function markdownCell(value: string): string {
  return value.replaceAll("|", "\\|");
}

function readmeProblemKey(problem: ReadmeProblem): string {
  return `${problem.contest}/${problem.problem}`;
}

function readmeRow(problem: ReadmeProblem): string {
  return `| ${markdownCell(problem.contest)} | ${markdownCell(problem.problem)} | ${markdownCell(problem.rating)} | ${markdownCell(problem.topics)} |`;
}

function parseReadmeProblems(readme: string): ReadmeProblem[] {
  return readme
    .split("\n")
    .flatMap((line) => {
      if (!line.startsWith("| ") || line.includes("---")) {
        return [];
      }

      const cells = line
        .slice(1, -1)
        .split("|")
        .map((cell) => cell.trim());

      if (cells.length !== 4 || !/^\d+$/.test(cells[0])) {
        return [];
      }

      return [
        {
          contest: cells[0],
          problem: cells[1],
          rating: cells[2],
          topics: cells[3],
        },
      ];
    });
}

function countValues(values: string[]): Array<[string, number]> {
  const counts = new Map<string, number>();

  for (const value of values) {
    counts.set(value, (counts.get(value) ?? 0) + 1);
  }

  return [...counts.entries()].sort(([left], [right]) =>
    left.localeCompare(right, undefined, { numeric: true }),
  );
}

function renderCountTable(
  title: string,
  label: string,
  rows: Array<[string, number]>,
): string {
  return [
    `## ${title}`,
    `| ${label} | Problems |`,
    "| --- | ---: |",
    ...rows.map(([name, count]) => `| ${markdownCell(name)} | ${count} |`),
  ].join("\n");
}

function renderSolutionsReadme(problems: ReadmeProblem[]): string {
  const sortedProblems = [...problems].sort((left, right) =>
    readmeRow(left).localeCompare(readmeRow(right), undefined, {
      numeric: true,
    }),
  );
  const ratingCounts = countValues(
    sortedProblems.map((problem) => problem.rating || "unrated"),
  );
  const topicCounts = countValues(
    sortedProblems.flatMap((problem) =>
      problem.topics
        ? problem.topics.split(",").map((topic) => topic.trim())
        : ["untagged"],
    ),
  );

  return [
    renderCountTable("Rating Counts", "Rating", ratingCounts),
    renderCountTable("Topic Counts", "Topic", topicCounts),
    "## Problems",
    "| Contest | Problem | Rating | Topics |",
    "| --- | --- | --- | --- |",
    ...sortedProblems.map(readmeRow),
    "",
  ].join("\n");
}

async function updateSolutionsReadme(items: PlannedSubmission[]): Promise<void> {
  const existing = await Bun.file(readmePath).text().catch(() => "");
  const problems = new Map(
    parseReadmeProblems(existing).map((problem) => [
      readmeProblemKey(problem),
      problem,
    ]),
  );

  for (const item of items) {
    const problem = readmeProblemFromSubmission(item.submission);
    problems.set(readmeProblemKey(problem), problem);
  }

  await Bun.write(readmePath, renderSolutionsReadme([...problems.values()]));
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
    const fetchedItems = [];

    for (const item of items) {
      fetchedItems.push(await fetchPlannedSubmission(item));
    }

    for (const item of fetchedItems) {
      await writeSubmission(item);
    }

    await updateSolutionsReadme(fetchedItems);
    await commitPaths(`Add ${items.length} Codeforces submissions`, [
      ...items.map((item) => item.path),
      readmePath,
    ]);
    return;
  }

  for (const item of items) {
    const fetchedItem = await fetchPlannedSubmission(item);

    await writeSubmission(fetchedItem);
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
  await updateSolutionsReadme(validPlanned);
  console.log("No new submissions to write.");
}
