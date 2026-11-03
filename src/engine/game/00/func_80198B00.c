#include "game_00.h"

MATCH void func_80198B00(void) {
    Area_DispatchScene();
    func_80199308();
    if (g_GameStateIndex == 0) {
        g_GameEntryState = 2;
    }
}
