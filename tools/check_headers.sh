#!/bin/sh
# Finish `check-headers`: the probes are built, so confirm every header has one.
#
#   tools/check_headers.sh HEADER_LIST    the list `meson setup` wrote
set -eu
cd "$(dirname "$0")/.."

now=$(find include src -name '*.h' | sort)
if [ "$now" != "$(sort "$1")" ]; then
	echo "check-headers: a header was added or removed since the last configure." >&2
	echo "check-headers: run: meson setup --reconfigure build/meson" >&2
	exit 1
fi
echo "check-headers: ok"
