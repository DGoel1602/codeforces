Codeforces

## Watch a user's rating

Run this to poll Codeforces and get notified when a user's rating changes:

```sh
bun run watch-rating <codeforces-handle>
```

The script stores the last seen rating in `.codeforces-rating-state.json`.
By default it checks every 10 minutes and tries to use the system desktop
notifier (`notify-send` on Linux, `osascript` on macOS). It also rings the
terminal bell and prints the change.

Useful options:

```sh
bun run watch-rating <codeforces-handle> --interval 60
bun run watch-rating <codeforces-handle> --once
bun run watch-rating <codeforces-handle> --notify-command 'echo "$CF_HANDLE $CF_OLD_RATING -> $CF_NEW_RATING"'
```
