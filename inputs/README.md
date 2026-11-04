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

The Redump set is often kept as one 7-Zip archive. To recognise yours, compare it with this one,
which holds exactly the three files in `config/disc.toml`:

| Archive                        | Size (bytes) | SHA-1                                      |
| ------------------------------ | -----------: | ------------------------------------------ |
| `Breath of Fire III (USA).7z`  |   81,031,216 | `da46b0db8e7bf0d2afacc78e4848ab7c74eda370` |

| File inside                              | Size (bytes) | CRC32      |
| ---------------------------------------- | -----------: | ---------- |
| `Breath of Fire III (USA).cue`           |          218 | `ad7dc790` |
| `Breath of Fire III (USA) (Track 1).bin` |  442,938,048 | `4d5b0d4b` |
| `Breath of Fire III (USA) (Track 2).bin` |   37,396,800 | `7976083e` |

An archive with another hash can still be right: the track hashes decide. Unpack it into
`inputs/external/`.

`tools/setup.sh` checks both track files before it extracts, then every extracted file and every
code image, and names each one that differs. Check again at any time with `tools/disc.py verify`
([disc manifest](../docs/toolchain.md#disc-manifest)).
