#include "game_00.h"

MATCH void func_8019BEFC(void) {
    Actor* work;
    u8     count;
    work  = g_SpadWork;
    count = work->unk_09;
    if (count != 0) {
        work->unk_09 = (u8)(count - 1);
    }
    if (g_AreaCameraMoving == 0) {
        work = g_SpadWork;
        if (work->unk_09 == 0) {
            work->unk_01 = 1;
            func_8019BFD4();
        }
    }
    func_8014D978();
    Area_SetDrawMode();
}
