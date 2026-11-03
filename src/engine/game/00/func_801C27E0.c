#include "game_00.h"

MATCH bool func_801C27E0(s8 tuning_delta) {
    if (func_801C2894(tuning_delta) & BYTE_MASK) {
        GFX_StagePalette((u32)((g_SpadWork->unk_05 << 6) + (s32)MEM_PTR(u8, 0x80035600u)), 0);
        g_SpadWork->flags_00 &= ~ACTOR_FLAG_SEMI_TRANSPARENT;
        g_SpadWork->tint.bytes.unk_5D = 0;
        g_SpadWork->tint.bytes.unk_5E = 0;
        g_SpadWork->tint.bytes.unk_5F = 0;
        g_SpadWork->tint.bytes.flags  = 0;
        return true;
    }
    return false;
}
