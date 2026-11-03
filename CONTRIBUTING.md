# Contributing to bof3-decomp

bof3-decomp recovers readable C89 that compiles to the retail bytes of *Breath of Fire III* (US,
PlayStation). A good change keeps those bytes and explains the code with evidence.

## Ways to help

| You have        | Start with                                                                                                                                                  |
| --------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------- |
| No disc         | Fix a docs page; improve the [BOF3 wiki](https://github.com/raulcorreia7/bof3-wiki); add a test to [bof3-tools](https://github.com/raulcorreia7/bof3-tools) |
| A disc          | [Match one function](#your-first-match); rename a function or global whose purpose you can prove                                                            |
| A game question | Ask in [Discussions](https://github.com/raulcorreia7/bof3-decomp/discussions)                                                                               |

Open an issue before a large change, such as a new header layout or a rename across images.

## Set up

Follow the [README quick start](README.md#quick-start). The host tools and what each does are in the
[toolchain guide](docs/toolchain.md#host-tools). Keep the disc, the extracted data and the
toolchain objects local: they are ignored by Git and never belong in a commit.

For the permuter, the differ and m2c, run `tools/setup.sh --dev --matching` instead.

## Your first match

A function is `TARGET@0xADDRESS`; `<image>` is the target with `/` written as `+`
(`exe/slus_004_22` is `exe+slus_004_22`). This walkthrough needs a disc.

1. **Pick a function.** An unmatched function is one `INCLUDE_ASM(func_<ADDR>);` line in its own
   `.c` file. List them in one image and take a small one:

   ```sh
   git grep -c INCLUDE_ASM -- src/engine/slus
   wc -l asm/exe/slus_004_22/func_<ADDR>.s     # the split assembly; fewer lines are easier
   ```

2. **Look for a twin.** A matched body with the same instructions is shared, not lifted again.
   Build once, then search ([coddog](docs/toolchain.md#coddog)):

   ```sh
   meson compile -C build/meson
   bin/coddog match exe/slus_004_22 func_<ADDR> -t 0.95
   ```

3. **Read.** Open `asm/exe/slus_004_22/func_<ADDR>.s` and its callers (`rg -uu 'jal\s+func_<ADDR>' asm/`).
   For a first draft, run [m2c](docs/toolchain.md#m2c) and restate its output as plain C.

4. **Write the C.** In the function's `.c` file, replace the `INCLUDE_ASM` line with a definition.
   Start the definition with the `MATCH` marker, and keep the address name above it:

   ```c
   /* func_8015C9CC */
   MATCH void Actor_ApplyVelocity(void) {
       ...
   }
   ```

   An unnamed function keeps its address name (`MATCH void func_<ADDR>(void)`). Names need
   evidence: [conventions](docs/conventions.md#names).

5. **Compare.** `tools/match.sh` builds the one object and compares the function with retail:

   ```sh
   tools/match.sh exe/slus_004_22@0x<ADDR>
   ```

   Exit 0 means equal. Exit 1 prints the first differing instruction for retail and for your code;
   label it and fix it by label ([diagnose](docs/matching.md#diagnose)). Exit 2 means nothing was
   compared, and the message says why ([match.sh](docs/toolchain.md#matchsh)).

6. **Polish.** Make the code read well while it still matches: real types and members, named
   constants, `for` loops, no pointer math ([polish](docs/matching.md#polish)).

7. **Prove it.** Only the image link accepts a match:

   ```sh
   meson compile -C build/meson check-exe+slus_004_22
   ```

   A function that cannot match yet stays `INCLUDE_ASM`, or a `NON_MATCHING` draft that records its
   score and first mismatch ([markers](docs/matching.md#markers-and-unmatched-bodies)).

A new header, a `NON_MATCHING` marker or an `asm/<target>/hand/` file needs
`meson setup --reconfigure build/meson` ([why](docs/toolchain.md#reconfigure)).

## Before you open a pull request

```sh
meson compile -C build/meson format
meson test -C build/meson
meson compile -C build/meson check check-headers check-tree include-asm format-check
```

Without a disc Meson does not offer `check`; leave it out. Each check:

| Check                    | Fails when                                             |
| ------------------------ | ------------------------------------------------------ |
| `check`, `check-<image>` | an image differs from its retail SHA-1                 |
| `check-headers`          | a public header does not compile alone                 |
| `check-tree`             | a tracked file is game data or over 1 MiB              |
| `include-asm`            | there are more `INCLUDE_ASM` lines than on `main`      |
| `format-check`           | C, Python, TOML or Markdown differs from the formatter |

The same disc-free checks run in CI on every push and pull request. A match score, an analyzer
opinion or a decompiler draft is a lead; only `check` proves bytes.

## Pull requests

- One topic per pull request: one function, or a small group with one cause.
- Commit subjects are `type(scope): subject`, imperative, lowercase, no final period, for example
  `fix(setup): validate disc tracks`.
- Name the targets and addresses, give the evidence for each new name or type, and list the checks
  you ran. The template has the checklist.
- Change generated files through their generator. Include source and synthetic fixtures only: no
  media, extracted assets, game executables, PsyQ objects or analysis databases.
- The maintainer reviews against [conventions](docs/conventions.md) and merges. Expect requests for
  evidence behind names and for the plain-C form of any helper.

## Questions and reports

Ask in [Discussions](https://github.com/raulcorreia7/bof3-decomp/discussions). Report a bug or a
wrong match as an [issue](https://github.com/raulcorreia7/bof3-decomp/issues/new/choose). Report a
security or conduct problem privately: [SECURITY.md](SECURITY.md),
[CODE_OF_CONDUCT.md](CODE_OF_CONDUCT.md).

## Coding agents

[AGENTS.md](AGENTS.md) and `.agents/skills/` are optional guidance for coding agents. You do not
need them. In them, "maintainer" is the repository owner, and `READY` and `BLOCKED` are the words an
agent ends its report with.

## License

The source is released under [CC0 1.0](LICENSE). By contributing you dedicate your contribution under
CC0, to the extent you own the rights; do not submit code you did not write or cannot license.
Third-party components keep their own terms: [NOTICE](NOTICE).
