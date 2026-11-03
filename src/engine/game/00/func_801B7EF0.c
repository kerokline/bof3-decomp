#include "game_00.h"

MATCH void func_801B7EF0(void) {
    s32 value;

    g_SpadWork->z.part.integer = Area_ReadHeight(g_SpadWork->x.fixed, g_SpadWork->y.fixed) + 0x200;
    value                      = 0x3D;
    if (g_SpadWork->direction_08 == 3) {
        value = 0x3C;
    }
    Actor_RequestScript(value);
    if (g_SpadWork->unk_05 != 0) {
        func_801C2438();
        g_SpadWork->tint.signed_bytes.unk_5D = -0x80;
        g_SpadWork->tint.signed_bytes.unk_5E = -0x80;
        g_SpadWork->tint.signed_bytes.unk_5F = -0x80;
        g_SpadWork->tint.bytes.flags         = 1;
        g_SpadWork->flags_00 &= ~ACTOR_FLAG_HIDDEN;
        g_SpadWork->unk_04 = 7;
    } else {
        g_SpadWork->unk_04 = 8;
    }
}
