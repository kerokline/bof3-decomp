#include "area082_13.h"

MATCH void func_801F336C(void) {
    void* temp_a0_14;

    temp_a0_14                    = SP_REF(void*, 0x44);
    FIELD(s16, temp_a0_14, 0x2Eu) = 0x100;
    FIELD(s16, temp_a0_14, 0x30u) = 0;
    FIELD(s16, temp_a0_14, 0x32u) = 0x18;
    FIELD(u8, temp_a0_14, 0x1u)   = (u8)(FIELD(u8, temp_a0_14, 0x1u) + 1);
}
