#include "area030_04.h"

/* Increments scratch byte 0x03 when the shared state byte is 6. */
MATCH void func_801D9E08(void) {
    u8* scratch;

    if (D_80144125 == 6) {
        scratch = (u8*)SP_REF(volatile u8*, 0x44u);
        scratch[3]++;
    }
}
