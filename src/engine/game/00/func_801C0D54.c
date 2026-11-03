#include "game_00.h"

MATCH void func_801C0D54(void) {
    u8 arg;

    if (func_801C0E48() & BYTE_MASK) {
        arg = 0x3B;
        if (g_SpadWork->direction_08 == 3)
            arg = 0x3A;
        Actor_RequestScript(arg);
        g_SpadWork->flags_00 &= ~ACTOR_FLAG_HIDDEN;
        g_SpadWork->z.part.integer = Area_ReadHeight(g_SpadWork->x.fixed, g_SpadWork->y.fixed) + 0x7D0;
        Actor_ClearVelocity();
        g_SpadWork->gravity  = -8;
        g_SpadWork->unk_01   = 2;
        g_SpadWork->state_02 = 3;
        g_SpadWork->unk_03   = 3;
        g_GameState->flags_12C.u8_value &= 0xFD;
    }
}
