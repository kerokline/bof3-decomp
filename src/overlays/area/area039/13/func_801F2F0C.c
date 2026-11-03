#include "area039_13.h"

MATCH void func_801F2F0C(void) {
    s32 var_a0;
    u8* var_v1;

    var_v1 = g_VitalItemIds;
    var_a0 = 0;
    do {
        if (*var_v1 == 0xE) {
            *var_v1 = 4;
            return;
        }
        var_a0 += 1;
        var_v1 += 1;
    } while ((u32)(var_a0 & BYTE_MASK) < 0x20U);
    Party_AddVitalItem(4);
}
