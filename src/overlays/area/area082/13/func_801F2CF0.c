#include "area082_13.h"

MATCH void func_801F2CF0(void) {
    u16   temp_v0_18;
    void* temp_a0_14;

    temp_a0_14                    = SP_REF(void*, 0x44);
    temp_v0_18                    = FIELD(u16, temp_a0_14, 0x2Cu) - 1;
    FIELD(u16, temp_a0_14, 0x2Cu) = temp_v0_18;
    if (!(temp_v0_18 & HALF_MASK)) {
        FIELD(u16, temp_a0_14, 0x2Cu) = 0xCU;
        FIELD(u8, temp_a0_14, 0x1u)   = (u8)(FIELD(u8, temp_a0_14, 0x1u) + 1);
    }
}
