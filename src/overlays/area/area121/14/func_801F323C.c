#include "area121_14.h"

MATCH void func_801F323C(void) {
    u8* work;
    u8* reload;
    u8  timer;

    Actor_CenterOnScreen();

    work    = (u8*)g_SpadWork;
    timer   = work[9];
    work[9] = timer - 1;
    reload  = (u8*)g_SpadWork;
    FIELD(s32, work, 0x40) += 0x2000;

    if (reload[9] == 0) {
        reload[0x48]       = 0;
        g_SpadWork->unk_01 = 3;
    }

    Area_AddActor();
}
