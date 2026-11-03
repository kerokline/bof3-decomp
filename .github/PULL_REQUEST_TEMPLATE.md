## What changed

Name the targets and addresses (`TARGET@0xADDRESS`) and the evidence for each new name or type.

## Checks

- [ ] `meson test -C build/meson` and `meson compile -C build/meson check-headers check-tree include-asm format-check` pass.
- [ ] `meson compile -C build/meson check` passes (needs a disc), or this change does not touch code.
- [ ] No game data, extracted assets, retail executables or PsyQ objects are included.
