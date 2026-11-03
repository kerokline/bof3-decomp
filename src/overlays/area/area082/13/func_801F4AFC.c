#include "area082_13.h"

MATCH void func_801F4AFC(void) {
    void* temp_v1_18;

    func_801F5388(0x80);
    temp_v1_18                  = SP_REF(void*, 0x44);
    D_8014933A                  = 1;
    FIELD(u8, temp_v1_18, 0x2u) = (u8)(FIELD(u8, temp_v1_18, 0x2u) + 1);
}
