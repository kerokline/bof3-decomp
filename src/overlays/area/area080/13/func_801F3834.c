#include "area080_13.h"

MATCH void func_801F3834(void) {
    s32 var_v1_17;

    D_801F44A4 = (s8*)(AREA_WORK_WINDOW + 0x6C);
    var_v1_17  = 0;
    do {
        var_v1_17 += 1;
        *D_801F44A4 = 0;
    } while ((u32)(var_v1_17 & BYTE_MASK) < 8U);
}
