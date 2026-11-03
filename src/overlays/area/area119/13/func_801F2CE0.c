#include "area119_13.h"

MATCH void func_801F2CE0(void) {
    u8* work;
    u8  value;

    work    = (u8*)g_SpadWork;
    value   = work[9];
    work[9] = value + 0xFF;
    if (value == 0) {
        g_SpadWork->unk_01 = 3;
    }
}
