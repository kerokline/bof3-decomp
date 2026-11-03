# Contributing to bof3-decomp

bof3-decomp recovers readable C89 that compiles to the retail bytes of *Breath of Fire III*
(US, PlayStation). A successful change preserves those bytes and explains the code
using evidence.

## Set up

Linux is the primary host. Use WSL2 on Windows. See the [toolchain guide](docs/toolchain.md)
for host tools and pinned dependencies.

```sh
git clone https://github.com/raulcorreia7/bof3-decomp.git
cd bof3-decomp
```

Install the host tools listed in the [toolchain guide](docs/toolchain.md#host-tools). Dump your own
US disc (a Redump-verified CUE sheet and two BIN tracks, described in
[inputs/README.md](inputs/README.md)) into `inputs/external/`. The repository holds no disc image
and you must not share yours. Without a disc
you can still edit and run the disc-free checks, but you cannot match a function
([details](docs/toolchain.md#without-a-disc)).

```sh
tools/setup.sh --dev          # add --matching for the permuter, differ and m2c
meson setup build/meson
meson compile -C build/meson check
```

Keep the disc, extracted payloads and toolchain objects local. Setup prepares the
generated build inputs; they are not source files to commit.

## Choose a change

Create a branch and choose one function or a small, related group.
Use the [matching guide](docs/matching.md) for a mismatch and the
[conventions](docs/conventions.md) for names, types, layout and comments.
The [toolchain guide](docs/toolchain.md) covers compilation, byte inspection,
diffing and the permuter.

Identify a function by its target and address. Equal addresses in different
targets are different functions. Keep an address-based name until evidence
establishes the function's meaning.

## Validate and submit

Run `meson compile -C build/meson check-<image>` while working on an image; `<image>` is the target
with `/` written as `+`, for example `check-exe+slus_004_22`. Before submitting, run:

```sh
meson test -C build/meson
meson compile -C build/meson check check-headers check-tree include-asm format-check
```

`check` verifies all 428 image checksums. The others verify standalone headers, tracked-file
restrictions, the unmatched-function count and formatting. Without a disc, Meson does not offer
`check`: leave it out of the command. Only `check` establishes a byte match; an analyzer score or a
decompiler draft does not.

Use a focused commit subject such as `fix(setup): validate disc tracks`.
In the pull request, name the targets and addresses, explain the evidence for
new names or types, and list the checks actually run.

Generated files change through their generator. Include source and synthetic
fixtures only; keep game media, extracted assets, game executables, PsyQ
objects and analysis databases outside the repository.

## Your first change

Pick the smallest step that fits what you have:

1. Fix a docs page. Edit a Markdown file in this repository and run `meson compile -C build/meson format-check`.
2. Improve a wiki page. The [BOF3 wiki](https://raulcorreia7.github.io/bof3-wiki/) takes pull requests at
   [bof3-wiki](https://github.com/raulcorreia7/bof3-wiki).
3. Add a Rust test to the disc and archive tools in
   [bof3-tools](https://github.com/raulcorreia7/bof3-tools).
4. With a disc, match one function. Run `tools/match.sh` on a `TARGET@0xADDRESS`, edit the C until the
   image matches, then run `meson compile -C build/meson check-<image>`.

Steps 1 to 3 need no disc (`tools/setup.sh --dev --no-payloads`).

## Where to ask

Ask questions and share ideas in
[GitHub Discussions](https://github.com/raulcorreia7/bof3-decomp/discussions) once enabled. Report a bug
or a mismatch as an issue. Report a security problem, or a conduct problem, privately: see
[SECURITY.md](SECURITY.md) and [CODE_OF_CONDUCT.md](CODE_OF_CONDUCT.md).

## Agent guidance

[AGENTS.md](AGENTS.md) and `.agents/skills/` are optional guidance for coding agents. You do not need
them to contribute. In them, "maintainer" means the repository owner, who reviews and merges pull
requests, and `READY` and `BLOCKED` are the status words an agent ends its report with.

## License

The source is released under [CC0 1.0](LICENSE). By contributing you agree that your contribution is
dedicated under CC0, to the extent you own the rights; do not submit code you did not write or
cannot license. Third-party components retain their own terms; see [NOTICE](NOTICE).
