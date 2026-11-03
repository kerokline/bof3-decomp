#include "area151_13.h"

MATCH void func_801F3194(void) {
    Actor* scratch;
    Actor* scratch2;
    u8     timer;

    Actor_CenterOnScreen();

    scratch         = (Actor*)g_SpadWork;
    timer           = scratch->unk_09;
    scratch->unk_09 = timer - 1;
    scratch2        = (Actor*)g_SpadWork;
    scratch->unk_40 += 0x2000;

    if (scratch2->unk_09 == 0) {
        scratch2->unk_48   = 0;
        g_SpadWork->unk_01 = 3;
    }

    Area_AddActor();
}
