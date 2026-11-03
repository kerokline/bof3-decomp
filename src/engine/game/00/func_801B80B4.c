#include "game_00.h"

MATCH void func_801B80B4(void) {
    s32 next_step;

    g_SpadWork->unk_09 = (u8)(g_SpadWork->unk_09 - 1);
    if (g_SpadWork->unk_09 != 0) {
        return;
    }
    g_SpadWork->unk_0A = (u8)(g_SpadWork->unk_0A + 1);
    if (g_SpadWork->direction_08 == 3) {
        next_step = 7;
        next_step -= g_SpadWork->unk_0A;
    } else {
        next_step = g_SpadWork->unk_0A;
        next_step += 1;
    }
    Actor_RequestScript((u8)next_step);
    if (g_SpadWork->unk_0A == 4) {
        if (g_SpadWork->unk_05 == 0) {
            g_AreaWalkFlags &= ~AREA_WALK_ENTRY_ACTIVE;
        }
        g_SpadWork->unk_09 = 0;
        g_SpadWork->unk_0A = 0;
        g_SpadWork->unk_01 = 1;
        ACTOR_CLEAR_STATE();
        g_SpadWork->unk_03 = 0;
        g_SpadWork->unk_04 = 0;
    } else {
        g_SpadWork->unk_09 = 2;
    }
}
