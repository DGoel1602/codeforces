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

console.log(`Found ${accepted.length} final AC submissions for ${handle}.`);
console.log(
  `${validPlanned.length} use C++, Java, C, or Python and can be saved.`,
);
console.log(`${missing.length} submissions are not in solutions/ yet.`);

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
