#include "area077_14.h"

MATCH void func_801F533C(void) {
    u8* work;

    work                 = SP_REF(u8*, 0x44);
    *(u16*)(work + 0x3E) = 0x320;
    work[2] += 1;
    func_801F54B8();
}
