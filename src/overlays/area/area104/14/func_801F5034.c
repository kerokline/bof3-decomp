#include "area104_14.h"

MATCH s32 func_801F5034(void) {
    if ((g_InputPressed & D_80145AB8) == 0) {
        return 0;
    }
    if (g_GameFlags & GAME_FLAG_RUN_LOCK) {
        return 0;
    }
    SND_PlayCue(EMI_CUE_ID(1, 5));
    g_GameStateIndex = GAME_REQUEST_MENU;
    ACTOR_CLEAR_STATE();
    return 1;
}
