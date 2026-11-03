#include "area052_13.h"

MATCH void func_801F3194(void) {
    s32   var_v1_15;
    void* var_a0_14;

    var_a0_14 = (void*)AREA_WORK_WINDOW;
    var_v1_15 = 0;
    do {
        FIELD(s8, var_a0_14, 0x15u) = 0;
        var_v1_15 += 1;
        var_a0_14 += 0x18;
    } while ((u32)(var_v1_15 & BYTE_MASK) < 0x10U);
}
