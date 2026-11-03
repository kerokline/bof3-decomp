#!/bin/sh
# Reject tracked retail media and files over 1 MiB. Needs no build inputs.
set -eu
cd "$(dirname "$0")/.."

bad=$(git ls-files -z | xargs -0 stat -c '%s %n' | awk '{
	name = substr($0, length($1) + 2)
	if ($1 > 1048576 || tolower(name) ~ /\.(bin|iso|img|cue|exe|psx|7z|mdf|ccd|ecm)$/) print name
}')
if [ -n "$bad" ]; then
	echo "check-tree: retail data or oversized files tracked:"
	echo "$bad"
	echo "check-tree: run: git rm --cached <file>, and keep game data under inputs/ or build/"
	exit 1
fi
echo "check-tree: ok"
