#include "game_00.h"

MATCH void func_801B781C(void) {
    if ((func_8014DAEC() & BYTE_MASK) != 0 && (func_801C2AAC() & BYTE_MASK) == 0) {
        Actor_RequestScript(g_SpadWork->direction_08);
        g_GameState->mode_12B.u8_value = 0;
        g_SpadWork->unk_01             = 1;
        ACTOR_CLEAR_STATE();
        g_SpadWork->unk_03 = 0;
    }
}
