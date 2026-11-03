#include "area013_13.h"

MATCH void func_801F2E18(void) {
    void* temp_v1_14;

    temp_v1_14                  = SP_REF(void*, 0x44);
    FIELD(u8, temp_v1_14, 0x8u) = (u8)((FIELD(u8, temp_v1_14, 0x8u) + 1) & 7);
}
