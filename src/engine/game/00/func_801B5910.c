#include "game_00.h"

MATCH s32 func_801B5910(void) {
    if (!(g_GameFlags & 0x2000)) {
        if (!(g_GameRequestFlags & 0x69) && (g_InputPressed & PADstart)) {
            func_801B5BDC(g_SpadWork->direction_08);
            g_GameStateIndex     = 9;
            g_SpadWork->unk_01   = 0xE;
            g_SpadWork->state_02 = 0;
            return 1;
        }
        return 0;
    }
    return 0;
}
