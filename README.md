# bof3-decomp

[![C match](https://raulcorreia7.github.io/bof3-status/badge.svg)](https://raulcorreia7.github.io/bof3-status/)

Matching decompilation of *Breath of Fire III* (US, PS1): each game function is recovered as
readable C89 that compiles to the retail bytes with the period compiler (GCC 2.7.2 PSX plus
maspsx). A function is `TARGET@0xADDRESS`, for example `exe/slus_004_22@0x8014AA04`.

Linux is the primary host; use WSL2 on Windows. The host tools are listed in the
[toolchain guide](docs/toolchain.md#host-tools). You need your own copy of the US
disc in `inputs/external/`: dump your own US disc ([inputs](inputs/README.md)). The repository
holds no disc image, executable or media.

```sh
git clone https://github.com/raulcorreia7/bof3-decomp.git
cd bof3-decomp
tools/setup.sh --dev                      # toolchain, Python environment, PsyQ, disc payloads
meson setup build/meson
meson compile -C build/meson check        # every image against its retail SHA-1
```

Without a disc, run `tools/setup.sh --dev --no-payloads`. You can then edit code and docs and run
the formatting, header and tree checks; you cannot build an image or match a function
([details](docs/toolchain.md#without-a-disc)). Build targets, the matching aids and the files that
need `meson setup --reconfigure build/meson`: [toolchain guide](docs/toolchain.md#commands).

The decompilation rules are in [docs/](docs/README.md): matching, naming, types, layout and
toolchain. Agent rules and the task skills are in [AGENTS.md](AGENTS.md). Game and format
references are in the
[BOF3 wiki](https://raulcorreia7.github.io/bof3-wiki/); a
comment that cites `@source: wiki:data/records` names a page of that wiki.
The disc, EMI and asset tools are pinned in the `tools/bof3-tools` submodule. `tools/setup.sh`
initializes it, builds the `bof3` CLI and uses it to extract the disc. Live progress:
<https://raulcorreia7.github.io/bof3-status/>.

## Contributing

Read [CONTRIBUTING.md](CONTRIBUTING.md) for setup, the matching workflow, checks
and pull request expectations.

## License

[CC0 1.0](LICENSE) for what contributors wrote, to the extent they own the rights. Breath of Fire III
belongs to Capcom; this project claims no rights over Capcom's code, data or marks. The source holds
decompiled code and data tables, and no media. The PsyQ headers in `include/psyq/` are Sony's,
included unmodified for interoperability. See [NOTICE](NOTICE).
