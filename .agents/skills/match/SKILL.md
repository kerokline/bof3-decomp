---
name: match
description: Match or polish one bof3-decomp function (TARGET@0xADDRESS) to the retail bytes as readable C89, or report the exact blocker. Use for a single-function match, a retry or a diff fix.
---

# Match one function

Input: `TARGET@0xADDRESS` from the task. Only `check-<image>` exit 0 accepts a candidate ([commands](../../../docs/toolchain.md#commands)).

1. Dedupe: `bin/coddog match <target> <func>` ([coddog](../../../docs/toolchain.md#coddog)). A matched
   twin is reused and shared ([shared bodies](../../../docs/conventions.md#shared-bodies)), not lifted again;
   a twin in the same image is `<Name>_<ADDR>` with the group's statement macro as its body. For a
   close but not equal function, `tools/template_diff.py <target>@<func>` lists the matched
   templates and prints only the instructions that differ ([templates](../../../tools/README.md#templates));
   `tools/template_try.py rows.tsv` tries many pairs and keeps the exact ones.
2. Seed: read `asm/<target>/func_<ADDR>.s`, its callers and its prototypes
   ([loop](../../../docs/matching.md#the-loop)). Draft in `work/<image>/<ADDR>/`.
3. Measure: put the draft in the unit's `.c` and run `tools/match.sh <target> <func>`
   ([match.sh](../../../docs/toolchain.md#matchsh)): `match` or the first differing instruction in
   about 0.1 s. A refusal (exit 2) names the reason; for a function with a jump table or data use
   the `cc` wrapper and objdiff ([toolchain](../../../docs/toolchain.md#compiler-wrapper)). Label
   the first hunk and fix it by label ([diagnose](../../../docs/matching.md#diagnose)).
4. Helpers only after pure C fails, benign before harmful, each with its `FAKE:` note
   ([helpers](../../../docs/conventions.md#fake-match-helpers)). A near-match goes to the
   [permuter](../../../docs/matching.md#permuter).
5. Polish the exact candidate ([polish](../../../docs/matching.md#polish)), re-run `match.sh`.
   `match.sh` is a lead: it compares `.text` only.
6. Gate: `check-<image>`, then `check`. After a type or signature change run
   `tools/typeloss.py origin/main WORK` and `tools/sigs.py scan <path>`. Run the
   [quality pass](../review/SKILL.md#quality-pass) on your diff.

Report: `exact` (candidate path, `check-<image>` result), `blocked` (cause, first diff,
falsified hypotheses with measurements, best score, the one lever that would change it) or `needs`
([need lines](../../../docs/matching.md#residuals)). Last line `READY <sha>` or `BLOCKED <reason>`.
