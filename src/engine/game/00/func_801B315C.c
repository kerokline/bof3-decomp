#include "game_00.h"

MATCH void func_801B315C(void) {
    if (g_GameStateIndex == 0) {
        if (g_GameRequestFlags & 1) {
            func_801B5BDC(g_SpadWork->direction_08);
        } else {
            Actor_RequestScript(g_SpadWork->direction_08);
        }
        g_SpadWork->unk_01 = 1;
        ACTOR_CLEAR_STATE();
    }
}
