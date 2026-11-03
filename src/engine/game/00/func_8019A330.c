#include "game_00.h"

MATCH void func_8019A330(void) {
    if (LOHU(g_GameAreaId) == 0x68) {
        func_801F53D4();
        return;
    }
    func_801F5918();
}
