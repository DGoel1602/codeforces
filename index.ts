import { mkdir } from "node:fs/promises";
import { dirname } from "node:path";
import { fetchSubmissions, type Submission } from "./codeforces";
import { SolutionsReadme } from "./solutions-readme";

type AcceptedSubmission = {
	contestId: number;
	submission: Submission;
};

type Solution = AcceptedSubmission & { path: string };
type PreparedSolution = Solution & { source: string };
type ArchivePlan = {
	acceptedCount: number;
	supported: Solution[];
	missing: Solution[];
};

const commitSplitThreshold = 20;
const readmePath = "solutions/README.md";

async function main(args: string[]): Promise<void> {
	const handle = args[0];
	if (!handle) throw new Error("Usage: bun run index.ts <codeforces-handle>");

	const key = Bun.env.CF_API_KEY;
	const secret = Bun.env.CF_API_SECRET;
	const submissions = await fetchSubmissions(
		handle,
		key && secret ? { key, secret } : undefined,
	);

	const plan = await planArchive(submissions);
	printPlan(handle, plan);

	const prepared = plan.missing.map((solution) => ({
		...solution,
		source: submissionSource(solution.submission, handle),
	}));
	const readme = await SolutionsReadme.read(readmePath);

	if (prepared.length === 0) {
		for (const solution of plan.supported) {
			readme.add(solution.contestId, solution.submission.problem);
		}

		await readme.write();
		console.log("No new submissions to write.");
		return;
	}

	if (prepared.length > commitSplitThreshold) {
		await writeAndCommit(
			prepared,
			readme,
			`Add ${prepared.length} Codeforces submissions`,
		);
	} else {
		for (const solution of prepared) {
			const problem = `${solution.contestId}${solution.submission.problem.index.toUpperCase()}`;
			await writeAndCommit(
				[solution],
				readme,
				`Add Codeforces ${problem}`,
			);
		}
	}

	console.log(`Wrote and committed ${prepared.length} submissions.`);
}

async function planArchive(submissions: Submission[]): Promise<ArchivePlan> {
	const accepted = latestAccepted(submissions);
	const supported: Solution[] = [];
	const missing: Solution[] = [];

	for (const { contestId, submission } of accepted) {
		const extension = extensionForLanguage(submission.programmingLanguage);
		if (!extension) continue;

		const index = submission.problem.index.toLowerCase();
		const path = `solutions/${contestId}/${index}.${extension}`;
		const solution = { contestId, path, submission };

		supported.push(solution);
		if (!(await Bun.file(path).exists())) missing.push(solution);
	}

	return { acceptedCount: accepted.length, supported, missing };
}

function latestAccepted(submissions: Submission[]): AcceptedSubmission[] {
	const byProblem = new Map<string, AcceptedSubmission>();

	// user.status returns newest submissions first; choose before filtering languages.
	for (const submission of submissions) {
		const contestId = submission.problem.contestId ?? submission.contestId;
		if (submission.verdict !== "OK" || !contestId) continue;

		const key = `${contestId}/${submission.problem.index.toLowerCase()}`;
		if (!byProblem.has(key)) byProblem.set(key, { contestId, submission });
	}

	const compareIndexes = new Intl.Collator(undefined, { numeric: true })
		.compare;

	return [...byProblem.values()].sort(
		(left, right) =>
			left.contestId - right.contestId ||
			compareIndexes(
				left.submission.problem.index,
				right.submission.problem.index,
			),
	);
}

function extensionForLanguage(language: string): string | null {
	const name = language.toLowerCase();

	if (name.includes("c++")) return "cpp";
	if (name.includes("python") || name.includes("pypy")) return "py";
	if (name.startsWith("java ")) return "java";
	if (name.includes("gnu c") || name === "c") return "c";
	return null;
}

function submissionSource(submission: Submission, handle: string): string {
	let source = submission.source;

	if (source == null && typeof submission.sourceBase64 === "string") {
		source = Buffer.from(submission.sourceBase64, "base64").toString(
			"utf8",
		);
	}

	if (typeof source !== "string" || !source) {
		throw new Error(
			`Submission ${submission.id} did not include source. ` +
				`Set CF_API_KEY and CF_API_SECRET for the Codeforces account ` +
				`"${handle}", then rerun.`,
		);
	}

	return `${source.replaceAll("\r\n", "\n").trimEnd()}\n`;
}

function printPlan(handle: string, plan: ArchivePlan): void {
	const { missing } = plan;
	const mode =
		missing.length > commitSplitThreshold
			? "one batch commit"
			: "one commit per submission";

	console.log(
		[
			`Found ${plan.acceptedCount} final AC submissions for ${handle}.`,
			`${plan.supported.length} use C++, Java, C, or Python and can be saved.`,
			`${missing.length} submissions are not in solutions/ yet.`,
			`Commit mode for this run: ${mode}.`,
		].join("\n"),
	);

	for (const { path, contestId, submission } of missing.slice(0, 10)) {
		const { problem } = submission;
		const rating = problem.rating ?? "unrated";
		const tags = problem.tags.join(", ") || "no tags";

		console.log(
			`${path} <- submission ${submission.id}: ` +
				`${contestId}/${problem.index.toLowerCase()} - ${problem.name} ` +
				`(${rating}) [${submission.programmingLanguage}; ${tags}]`,
		);
	}

	if (missing.length > 10) console.log(`...and ${missing.length - 10} more.`);
}

async function writeAndCommit(
	items: PreparedSolution[],
	readme: SolutionsReadme,
	message: string,
): Promise<void> {
	for (const item of items) {
		await mkdir(dirname(item.path), { recursive: true });
		await Bun.write(item.path, item.source);
		readme.add(item.contestId, item.submission.problem);
	}

	await readme.write();

	const paths = [...items.map((item) => item.path), readme.path];
	runGit(["add", "--", ...paths]);
	runGit(["commit", "--only", "-m", message, "--", ...paths]);
}

function runGit(args: string[]): void {
	const child = Bun.spawnSync(["git", ...args], {
		stdout: "pipe",
		stderr: "pipe",
	});

	if (child.exitCode !== 0) {
		const output = [
			child.stdout.toString().trim(),
			child.stderr.toString().trim(),
		]
			.filter(Boolean)
			.join("\n");
		throw new Error(`git ${args.join(" ")} failed:\n${output}`);
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
