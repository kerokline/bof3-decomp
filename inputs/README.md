# inputs

Local, user-owned media. Nothing here is tracked. The game is not in this repository: dump your own
US disc (a Redump-verified CUE sheet and two BIN tracks), and never share it or commit it.

Put the CUE sheet and both BIN tracks in `inputs/external/`. `tools/setup.sh` extracts them to
`build/disc`. The ignored `inputs/external/private-assets/` cache holds the downloads
`tools/setup.sh` fetches (PsyQ 3.7, Sony's SDK, from archive.org at your own responsibility). Without media the disc step fails and names this directory; run
`tools/setup.sh --no-payloads` to set up for the disc-free checks
([toolchain](../docs/toolchain.md#without-a-disc)).

## The disc

The build targets *Breath of Fire III*, US release, serial `SLUS-00422` (Redump name
`Breath of Fire III (USA)`). [`config/disc.toml`](../config/disc.toml) lists the CUE sheet, both
tracks (size, CRC32, MD5, SHA-1) and every file of the disc (path, LBA, size, SHA-1). It requires a
CUE sheet that names the two separate BIN tracks.

`tools/setup.sh` checks both track files before it extracts, then every extracted file and every
code image, and names each one that differs. Check again at any time with `tools/disc.py verify`
([disc manifest](../docs/toolchain.md#disc-manifest)).
