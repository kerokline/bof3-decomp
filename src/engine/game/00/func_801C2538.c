#include "game_00.h"

/* ATTEMPT (insert/frame): the measured function matches instruction for
 * instruction except the frame: 40 bytes with `vars= 8` (`sw ra,0x20(sp)`,
 * `addiu sp,sp,-40`) against retail's 32 (`sw ra,0x18(sp)`, `addiu sp,sp,-32`).
 * The 8 bytes are two dead 4-byte slots; the only constructs that allocate
 * temps here are the two index multiplies `route_index_08 * 2` scaled by the
 * s32 element size (the sibling emi/etc/game/00@0x801A1AE4 has the same
 * `route * 2` index into an s32 table and the same dead `vars= 8` residual).
 * The matched in-unit twins func_801ABBA8 and func_8019B4A0 index the same
 * table through the FacingStep view (`g_FacingOffsets[idx].x/.y`), which
 * needs no index multiply in the source and folds to the same `sll
 * v0,v0,0x3; addu at,at,v0; lw .x/.y` addressing. No other change.
 */
MATCH void func_801C2538(void) {
    u8  rate;
    u32 step;
    s32 high;
    s32 pos_x;
    s32 pos_y;
    s16 result;

    /* Step size from route kind; rate from the shared selector bundle. */
    rate = g_RouteSpeedScale[g_GameState->counter_11C.u8_value];
    if ((g_SpadWork->direction_08 == 2) || (g_SpadWork->direction_08 == 6)) {
        step               = 0x20;
        g_SpadWork->unk_09 = (u8)step;
    } else {
        step               = 0x10;
        g_SpadWork->unk_09 = (u8)step;
    }
    g_SpadWork->unk_09 = (u8)(g_SpadWork->unk_09 / (u32)(rate & BYTE_MASK));
    if ((g_GameFlags & 0x1000) != 0) {
        g_SpadWork->unk_09 *= 2;
    }
    g_SpadWork->unk_0C = g_FacingOffsets[g_SpadWork->direction_08].x * rate;
    high               = g_FacingOffsets[g_SpadWork->direction_08].y * rate;
    g_SpadWork->unk_10 = high;
    pos_x              = g_SpadWork->x.fixed + g_SpadWork->unk_0C * g_SpadWork->unk_09;
    pos_y              = g_SpadWork->y.fixed + high * g_SpadWork->unk_09;
    result             = Area_ReadStepHeight(pos_x, pos_y, g_SpadWork->direction_08);
    if (SP_REF(volatile u8, 0x0u) != 0) {
        result = Area_ReadHeight(pos_x, pos_y);
    }
    g_SpadWork->vz = (result - g_SpadWork->z.part.integer) / g_SpadWork->unk_09;
}
