#include "battle_15.h"

/* Follows etc/game/00 func_801999F8 (the inventory panel) with the narrow layout: window 130x20, rows 7, y offsets 122/112/120, fewer UI_DrawSprite loops (sltiu 12 and 9).
 * First differing instruction: +0x010 `li a3,130` (template `li a3,154`); the tail also differs from +0x64C: the func_801AFA1C call takes seven rows and the 0x20 flag arm comes first. */
INCLUDE_ASM(func_800B25C0);
