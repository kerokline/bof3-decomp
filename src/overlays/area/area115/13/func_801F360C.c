#include "area115_13.h"

MATCH void func_801F360C(void) {
    Actor* work;
    s16    origin_x;
    u8     mode;

    work         = g_SpadWork;
    origin_x     = work->unk_2E - 0x10;
    work->unk_2E = origin_x;
    if (origin_x < -47) {
        work->state_02 = 0;
    }

    if (D_801454F2 != 2) {
        mode           = 1;
        work           = g_SpadWork;
        work->state_02 = mode;
    }

    Area_DrawHud(0x10, g_SpadWork->unk_2E);
}
