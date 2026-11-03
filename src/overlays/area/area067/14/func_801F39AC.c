#include "area067_14.h"

MATCH void func_801F39AC(void) {
    s32   var_v1_15;
    void* var_a0_14;

    var_a0_14 = (void*)AREA_WORK_WINDOW;
    var_v1_15 = 0;
    do {
        FIELD(s16, var_a0_14, 0xCu) = 0;
        var_v1_15 += 1;
        var_a0_14 += 0xE;
    } while ((u32)(var_v1_15 & BYTE_MASK) < 0x80U);
}
