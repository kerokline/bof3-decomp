#include "area082_13.h"

MATCH void func_801F2C6C(void) {
    void* temp_v0_14;

    temp_v0_14                    = SP_REF(void*, 0x44);
    FIELD(s16, temp_v0_14, 0x2Cu) = 0x20;
    FIELD(s32, temp_v0_14, 0x64u) = 0;
    FIELD(s32, temp_v0_14, 0x68u) = 0;
    FIELD(s32, temp_v0_14, 0x6Cu) = 0;
    FIELD(u8, temp_v0_14, 0x1u)   = (u8)(FIELD(u8, temp_v0_14, 0x1u) + 1);
}
