---
name: refactor
description: Restructure bof3-decomp source with the bytes unchanged. Use for a struct layout, a cast cleanup, a constant or flag, a union, a shared twin body, a helper inline, or a declaration or header move.
---

# Refactor with identical bytes

Input: the task `scope` and its `writes` list, the paths it lets you change ([rule 1](../../../AGENTS.md#standing-rules)). Every touched image stays EXACT.

1. Collect every access or copy across all images: the split assembly, `bin/rz <target> 'axt @ SYM'`
   and `rg -n '\bSYM\b' src include` ([users of a symbol](../../../docs/toolchain.md#every-user-of-a-symbol)).
   One access proves the access, not the layout. A width must match every access.
2. Choose the form:
   - a type, member or cast: [types](../../../docs/conventions.md#types-and-values);
   - a value: [values](../../../docs/conventions.md#values);
   - a declaration, header or file move: [layout](../../../docs/conventions.md#lowest-scope-wins);
   - a twin group: `bin/coddog cluster <target>`, then
     [shared bodies](../../../docs/conventions.md#shared-bodies);
   - a repeated operation: [helpers and macros](../../../docs/conventions.md#helpers-and-macros).
3. Declare once at the lowest scope, add `ASSERT_SIZE` and an `ASSERT_OFFSET` per proven member,
   convert each consumer, and delete its cast or view. A cast that breaks the match stays as
   `kept: <reason>`.
4. Run `check-<image>` for every image that uses the symbol. Share only when every member is
   exact; pull the share back when one diverges.
5. Gate: `check`. Run the [quality pass](../review/SKILL.md#quality-pass).

A missing shared type outside the grant is a `needs: type <Type>+0xOFF <width> (<n> sites)` line.

Report: `typed` or `shared` (record, member or group, the accesses that prove it, owning header),
`kept` (the access that still matches, and why) or `needs`. Last line `READY <sha>` or
`BLOCKED <reason>`.
