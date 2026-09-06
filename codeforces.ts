import { createHash, randomBytes } from "node:crypto";

export type Credentials = { key: string; secret: string };

export type Problem = {
  contestId?: number;
  index: string;
  name: string;
  rating?: number;
  tags: string[];
};

export type Submission = {
  id: number;
  contestId?: number;
  programmingLanguage: string;
  verdict?: string;
  problem: Problem;
  source?: string;
  sourceBase64?: string;
};

export async function fetchSubmissions(
  handle: string,
  credentials?: Credentials,
): Promise<Submission[]> {
  const params: Record<string, string> = { handle };
  if (credentials) params.includeSources = "true";
  const submissions = (await request("user.status", params, credentials)) as Submission[];

  for (const submission of submissions) {
    const problem = submission?.problem;
    if (
      !submission ||
      !Number.isSafeInteger(submission.id) ||
      typeof submission.programmingLanguage !== "string" ||
      !problem ||
      typeof problem.index !== "string" ||
      !/^[a-z\d]+$/i.test(problem.index) ||
      typeof problem.name !== "string" ||
      !Array.isArray(problem.tags) ||
      !problem.tags.every((tag) => typeof tag === "string") ||
      (problem.rating !== undefined && !Number.isSafeInteger(problem.rating)) ||
      [submission.contestId, problem.contestId].some(
        (id) => id !== undefined && (!Number.isSafeInteger(id) || id <= 0),
      )
    ) {
      throw new Error("Codeforces user.status returned an invalid submission");
    }
  }
  return submissions;
}

export async function fetchRating(handle: string): Promise<number | null> {
  const users = await request("user.info", { handles: handle });
  const user = users[0] as { handle: string; rating?: number } | undefined;
  if (!user || typeof user.handle !== "string") {
    throw new Error(`Codeforces did not return a user for "${handle}"`);
  }
  if (user.rating !== undefined && !Number.isSafeInteger(user.rating)) {
    throw new Error(`Codeforces returned an invalid rating for "${handle}"`);
  }
  return user.rating ?? null;
}

async function request(
  method: string,
  params: Record<string, string>,
  credentials?: Credentials,
): Promise<unknown[]> {
  const response = await fetch(apiUrl(method, params, credentials), {
    signal: AbortSignal.timeout(30_000),
  });
  if (!response.ok) throw new Error(`Codeforces returned HTTP ${response.status}`);

  const body = (await response.json()) as {
    status?: unknown;
    comment?: unknown;
    result?: unknown;
  } | null;
  if (body?.status === "FAILED") throw new Error(`Codeforces: ${body.comment}`);
  if (body?.status !== "OK" || !Array.isArray(body.result)) {
    throw new Error(`Codeforces ${method} returned an invalid response`);
  }
  return body.result;
}

function apiUrl(method: string, params: Record<string, string>, credentials?: Credentials): URL {
  const url = new URL(`https://codeforces.com/api/${method}`);
  url.search = new URLSearchParams(params).toString();
  if (!credentials) return url;

  url.searchParams.set("apiKey", credentials.key);
  url.searchParams.set("time", Math.floor(Date.now() / 1000).toString());
  url.searchParams.sort();
  const prefix = randomBytes(3).toString("hex");
  const signature = createHash("sha512")
    .update(`${prefix}/${method}?${url.searchParams}#${credentials.secret}`)
    .digest("hex");
  url.searchParams.set("apiSig", prefix + signature);
  return url;
}
