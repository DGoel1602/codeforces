const handle = Bun.argv[2];

if (!handle) {
  console.error("Usage: bun run index.ts <codeforces-handle>");
  process.exit(1);
}

console.log(`Ready to fetch final AC submissions for ${handle}.`);
