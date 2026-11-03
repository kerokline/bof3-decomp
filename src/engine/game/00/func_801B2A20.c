#include "game_00.h"

MATCH void func_801B2A20(void) {
    if (g_GameStateIndex != 1) {
        g_AreaWalkFlags &= ~AREA_WALK_RUN_ACTIVE;
        g_SpadWork->unk_01 = 1;
        ACTOR_CLEAR_STATE();
    }
}
