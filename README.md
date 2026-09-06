# Codeforces archive and rating watch

Requires Bun and Git. Install the development tools with `bun install --frozen-lockfile`.

## Archive accepted submissions

Run from this repository with a Git author name and email configured:

```sh
bun run start <codeforces-handle>
```

For source access, put the account's API credentials in the ignored `.env` file:

```dotenv
CF_API_KEY=your-key
CF_API_SECRET=your-secret
```

Codeforces only provides submission sources for your own account. Generate keys in
[API settings](https://codeforces.com/settings/api); see the
[user.status documentation](https://codeforces.com/apiHelp/methods#user.status).

The script selects the latest accepted submission for each problem and supports
C++, Python/PyPy, Java, and C. It saves missing files under
`solutions/<contest>/<problem>.<extension>` and updates `solutions/README.md` with
problem details and rating/topic counts. Existing solution files are kept as-is.
If the latest accepted submission uses an unsupported language, that problem is
skipped, even if an older submission uses a supported language.

Up to 20 missing solutions get one commit each; larger runs get one batch commit.
Commits include only the new solutions and their README. The script creates local
commits; use `git push` when you want to publish them. A run with no new solutions
refreshes the README without committing it.

All missing sources and the existing README are read before writing solutions.
Missing sources or an unreadable README stop the run. If Git fails after files
have been written, inspect and commit those files before rerunning: existing files
are skipped on the next run.

## Watch a user's rating

```sh
bun run watch-rating <codeforces-handle>
bun run watch-rating <codeforces-handle> --interval 60
bun run watch-rating <codeforces-handle> --once
bun run watch-rating <codeforces-handle> --state state/rating.json
bun run watch-rating <codeforces-handle> --notify-command 'echo "$CF_HANDLE $CF_OLD_RATING -> $CF_NEW_RATING"'
```

The default interval is 600 seconds. `--interval` accepts whole seconds from 1 to 2147483. Codeforces limits API calls to [one every two seconds](https://codeforces.com/apiHelp),
so choose an interval that leaves room for other API use. Requests time out after
30 seconds. `--help` lists all options.

The first check establishes a baseline. Later rating changes print a message,
ring the terminal bell, and use `notify-send` on Linux or `osascript` on macOS.
If the desktop notifier is unavailable, the terminal message still counts as a
notification. A custom command replaces the desktop notification and receives
`CF_HANDLE`, `CF_OLD_RATING`, `CF_NEW_RATING`, and `CF_RATING_DELTA` in its environment.
Ratings use `unrated` when absent; the delta is empty when either rating is absent.

The state file remains `.codeforces-rating-state.json` by default, with the same
`handle`, `rating`, and `checkedAt` fields. Updates replace the file atomically.
Malformed state is reported and left intact. A failed custom notification command
keeps the previous rating so the next check can retry. `--once` exits with status 1
on failure; a continuous watch reports the error and retries after the interval.
Use separate state files for separate handles; changing the handle resets the baseline.

## Development

```sh
bun run format
bun run format:check
bun run check
bun test
```

Prettier uses tabs with a width of four. Archived submissions and their generated README
in `solutions/`, along with `bun.lock`, are excluded from formatting.

The two entry points keep their workflows in `src/index.ts` and `src/watch-rating.ts`.
`src/codeforces.ts` owns API requests, signing, and response validation.
`src/solutions-readme.ts` owns the archive table and its counts.

Tests run the CLIs with fake API responses and temporary Git repositories. They
cover archive selection, commit boundaries, preserved files and staged work,
README round trips, request signing, rating transitions, and failure handling.
