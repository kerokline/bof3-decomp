#include "area143_13.h"

MATCH void func_801F2D3C(void) {
    s32 var_a0_6;
    s8* var_a1_5;
    u8* var_v1_8;

    var_a1_5 = (s8*)AREA_WORK_WINDOW_ADDRESS;
    var_a0_6 = 0;
    var_v1_8 = (u8*)(AREA_WORK_WINDOW_ADDRESS + 2);
    do {
        *var_a1_5            = 0;
        *(s8*)(var_v1_8 - 1) = 0;
        *(s8*)var_v1_8       = 0;
        var_v1_8 += 0x18;
        var_a0_6 += 1;
        var_a1_5 += 0x18;
    } while ((u32)(var_a0_6 & HALF_MASK) < 0x100U);
}
