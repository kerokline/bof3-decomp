#include "game_00.h"

MATCH void func_801C56E4(void) {
    u8     index;
    Actor* work;
    Actor* state;

    work               = g_SpadWork;
    work->direction_08 = (u8)(work->direction_08 ^ 4);
    index              = 0x3B;
    if (g_SpadWork->direction_08 == 3) {
        index = 0x3A;
    }
    Actor_RequestScript(index);
    GFX_StagePalette((g_SpadWork->unk_05 << 6) + GAME_PALETTE_STAGE, 0);
    Actor_ClearVelocity();
    state                = g_SpadWork;
    state->gravity       = -8;
    state->unk_01        = 2;
    g_SpadWork->state_02 = 3;
    g_SpadWork->unk_03   = 3;
}
