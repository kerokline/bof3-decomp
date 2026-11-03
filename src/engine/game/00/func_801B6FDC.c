#include "game_00.h"

MATCH void func_801B6FDC(void) {
    if (g_GameStateIndex == 2) {
        return;
    }
    g_GameState->flags_118 &= 0xDFu;
    g_SpadWork->unk_03 = 0;
}
