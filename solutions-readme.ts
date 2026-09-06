import type { Problem } from "./codeforces";

type ReadmeProblem = {
  contest: string;
  problem: string;
  rating: string;
  topics: string;
};

const compareNames = new Intl.Collator(undefined, { numeric: true }).compare;

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
      if (cells.length !== 4) {
        throw new Error(`Malformed problem row in ${path}: ${line}`);
      }

      const [contest, problem, rating, topics] = cells;
      this.problems.set(`${contest}/${problem}`, {
        contest,
        problem,
        rating,
        topics,
      });
    }
  }

  static async read(path: string): Promise<SolutionsReadme> {
    let existing = "";

    try {
      existing = await Bun.file(path).text();
    } catch (error) {
      if ((error as NodeJS.ErrnoException).code !== "ENOENT") throw error;
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

    const ratings = problems.map((problem) => problem.rating || "unrated");
    const ratingCounts = countValues(ratings).sort(([left], [right]) =>
      compareNames(left, right),
    );

    const topics = problems.flatMap((problem) => {
      if (!problem.topics) return ["untagged"];

      return problem.topics.split(",").map((topic) => topic.trim());
    });
    const topicCounts = countValues(topics).sort(
      ([left, leftCount], [right, rightCount]) =>
        rightCount - leftCount || compareNames(left, right),
    );

    const readme = [
      countTable("Rating Counts", "Rating", ratingCounts),
      countTable("Topic Counts", "Topic", topicCounts),
      "## Problems",
      "| Contest | Problem | Rating | Topics |",
      "| --- | --- | --- | --- |",
      ...problems.map(problemRow),
      "",
    ].join("\n");

    await Bun.write(this.path, readme);
  }
}

function problemRow(problem: ReadmeProblem): string {
  const cells = [
    problem.contest,
    problem.problem,
    problem.rating,
    problem.topics,
  ];

  return `| ${cells.map(markdownCell).join(" | ")} |`;
}

function markdownCell(value: string): string {
  return value.replaceAll("|", "\\|");
}

function countValues(values: string[]): Array<[string, number]> {
  const counts = new Map<string, number>();

  for (const value of values) {
    counts.set(value, (counts.get(value) ?? 0) + 1);
  }

  return [...counts];
}

function countTable(
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
