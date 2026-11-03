#include "area082_13.h"

/* func_801F3910 */
MATCH void Area_ClearWorkColumn(void) {
    s32 var_v1_15;
    s8* var_a0_14;

    var_a0_14 = (s8*)AREA_WORK_WINDOW;
    var_v1_15 = 0;
    do {
        *var_a0_14 = 0;
        var_v1_15 += 1;
        var_a0_14 += 0x14;
    } while ((u32)(var_v1_15 & BYTE_MASK) < 0x80U);
}
