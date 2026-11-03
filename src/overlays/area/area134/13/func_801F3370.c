#include "area134_13.h"

MATCH void func_801F3370(void) {
    u8* work;
    u8  step;

    work    = (u8*)g_SpadWork;
    step    = work[2];
    work[2] = step + 1;
    if (step >= 15) {
        g_SpadWork->unk_01 = 0xD;
    } else {
        g_SpadWork->unk_01 = 0x14;
    }
}
