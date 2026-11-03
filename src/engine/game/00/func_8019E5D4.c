#include "game_00.h"

MATCH void func_8019E5D4(void) {
    s32 value;
    u8  sel;

    Area_FindSceneRecord(0x18);

    g_SpadWork->flags_24 = 0;
    g_SpadWork->unk_2A   = 0;
    g_SpadWork->unk_2B++;
    g_SpadWork->unk_48 = 0;

    value = rand();
    {
        Actor* coord = g_SpadWork;
        coord->x.fixed += value & HALF_MASK;
    }
    value = rand();
    {
        Actor* record   = g_SpadWork;
        record->gravity = -8;
        record->vz      = 0;
        record->y.fixed += value & HALF_MASK;
    }
    value = RANDOM_MASK(3);

    if (value >= 0) {
        sel = value;
        if (value >= 3) {
            sel = 2;
        }
    } else {
        sel = 0;
    }

    g_SpadWork->tint.bytes.unk_5D = 0;
    g_SpadWork->tint.bytes.unk_5E = 0;
    g_SpadWork->tint.bytes.unk_5F = 0;
    Actor_SelectScript(sel + 0xB);
    g_SpadWork->state_02++;
}
