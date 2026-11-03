#include "area134_13.h"

/* Dispatch the scratchpad state byte through the overlay's handler table. */
MATCH void func_801F3E0C(void) {
    SYS_DISPATCH_BYTE(D_801F5804, SP_REF(u8*, 0x44)[0x1]);
}
