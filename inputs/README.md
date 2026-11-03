# inputs

Local, user-owned media. Nothing here is tracked. The game is not in this repository: dump your own
US disc (a Redump-verified CUE sheet and two BIN tracks), and never share it or commit it.

Put the CUE sheet and both BIN tracks in `inputs/external/`. `tools/setup.sh` extracts them to
`build/disc`. The ignored `inputs/external/private-assets/` cache holds the downloads
`tools/setup.sh` fetches (PsyQ 3.7, Sony's SDK, from archive.org at your own responsibility). Without media the disc step fails and names this directory; run
`tools/setup.sh --no-payloads` to set up for the disc-free checks
([toolchain](../docs/toolchain.md#without-a-disc)).

`tools/setup.sh` checks both raw US track files against the
[Redump SHA-1 values](https://data.spludlow.co.uk/redump/redump/Sony%20-%20PlayStation/Breath%20of%20Fire%20III%20%28USA%29).
It requires a CUE sheet that names the two separate BIN tracks.
