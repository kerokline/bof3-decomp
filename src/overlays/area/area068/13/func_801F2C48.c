#include "area068_13.h"

MATCH void func_801F2C48(void) {
    void** scratchpad;
    void*  work;

    scratchpad            = SP_PTR(void*, 0u);
    work                  = scratchpad[0x44u / sizeof(void*)];
    FIELD(u8, work, 0x9u) = 0xB4;
    work                  = SP_REF(void*, 0x44u);
    FIELD(u8, work, 0x1u) = 1;
}
