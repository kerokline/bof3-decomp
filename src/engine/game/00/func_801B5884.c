#include "game_00.h"

MATCH s32 func_801B5884(void) {
    if (!(g_GameFlags & 0x2000) && (D_8014625C & D_80145ABA)) {
        g_GameStateIndex = 4;
        func_801B5BDC(g_SpadWork->direction_08);
        g_SpadWork->unk_01 = 1;
        ACTOR_CLEAR_STATE();
        return 1;
    }
    return 0;
}
