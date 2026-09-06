import type { Problem } from "./codeforces";

type ReadmeProblem = { contest: string; problem: string; rating: string; topics: string };

export class SolutionsReadme {
  private problems = new Map<string, ReadmeProblem>();

  private constructor(
    readonly path: string,
    existing: string,
  ) {
    let readingProblems = !existing.includes("## Problems");
    for (const line of existing.split("\n")) {
      if (line.startsWith("## ")) {
        readingProblems = line === "## Problems";
        continue;
      }
      if (!readingProblems || !line.startsWith("| ")) continue;
      const cells = line
        .slice(1, -1)
        .split(/(?<!\\)\|/)
        .map((cell) => cell.trim().replaceAll("\\|", "|"));
      if (!/^\d+$/.test(cells[0])) continue;
      if (cells.length !== 4) throw new Error(`Malformed problem row in ${path}: ${line}`);
      const [contest, problem, rating, topics] = cells;
      this.problems.set(`${contest}/${problem}`, { contest, problem, rating, topics });
    }
  }

  static async read(path: string): Promise<SolutionsReadme> {
    let existing: string;
    try {
      existing = await Bun.file(path).text();
    } catch (error) {
      if ((error as NodeJS.ErrnoException).code !== "ENOENT") throw error;
      existing = "";
    }
    return new SolutionsReadme(path, existing);
  }

  add(contestId: number, problem: Problem): void {
    const row = {
      contest: contestId.toString(),
      problem: `${problem.index}. ${problem.name}`,
      rating: problem.rating?.toString() ?? "",
      topics: problem.tags.join(", "),
    };
    this.problems.set(`${row.contest}/${row.problem}`, row);
  }

  async write(): Promise<void> {
    const problems = [...this.problems.values()].sort((left, right) =>
      compareNames(problemRow(left), problemRow(right)),
    );
    const ratings = countValues(problems.map((problem) => problem.rating || "unrated")).sort(
      ([left], [right]) => compareNames(left, right),
    );
    const topics = countValues(
      problems.flatMap((problem) =>
        problem.topics ? problem.topics.split(",").map((topic) => topic.trim()) : ["untagged"],
      ),
    ).sort(
      ([left, leftCount], [right, rightCount]) =>
        rightCount - leftCount || compareNames(left, right),
    );

    const readme = [
      countTable("Rating Counts", "Rating", ratings),
      countTable("Topic Counts", "Topic", topics),
      "## Problems",
      "| Contest | Problem | Rating | Topics |",
      "| --- | --- | --- | --- |",
      ...problems.map(problemRow),
      "",
    ].join("\n");
    await Bun.write(this.path, readme);
  }
}

function compareNames(left: string, right: string): number {
  return left.localeCompare(right, undefined, { numeric: true });
}

function markdownCell(value: string): string {
  return value.replaceAll("|", "\\|");
}

function problemRow(problem: ReadmeProblem): string {
  return `| ${[problem.contest, problem.problem, problem.rating, problem.topics].map(markdownCell).join(" | ")} |`;
}

function countValues(values: string[]): Array<[string, number]> {
  const counts = new Map<string, number>();
  for (const value of values) counts.set(value, (counts.get(value) ?? 0) + 1);
  return [...counts];
}

function countTable(title: string, label: string, rows: Array<[string, number]>): string {
  return [
    `## ${title}`,
    `| ${label} | Problems |`,
    "| --- | ---: |",
    ...rows.map(([name, count]) => `| ${markdownCell(name)} | ${count} |`),
  ].join("\n");
}
