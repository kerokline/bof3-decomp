#include "game_00.h"

MATCH void func_801B6AB0(void) {
    s32 x;

    x = g_SpadWork->x.fixed;
    if ((((x & 0x7FFF) != 0) || ((g_SpadWork->y.fixed & 0x7FFF) != 0)) && ((g_SpadWork->flags_24 & 0x20) == 0)) {
        g_SpadWork->x.fixed = (x + 0x4800) & ~0x7FFF;
        g_SpadWork->y.fixed = (g_SpadWork->y.fixed + 0x4800) & ~0x7FFF;
        g_SpadWork->z.part.integer =
            Area_ReadStepHeight(g_SpadWork->x.fixed, g_SpadWork->y.fixed, g_SpadWork->direction_08);
        Actor_RequestScript((g_SpadWork->direction_08 + 8) & BYTE_MASK);
        if (((g_SpadWork->x.fixed & 0x7FFF) == 0) && ((g_SpadWork->y.fixed & 0x7FFF) == 0)) {
            Actor_RequestScript(g_SpadWork->direction_08);
        }
    } else {
        Actor_ClearVelocity();
        g_SpadWork->unk_03++;
        func_801B6BC8();
    }
}
