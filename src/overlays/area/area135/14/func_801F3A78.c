#include "area135_14.h"

/* Dispatch the scratchpad state byte through the overlay's handler table. */
MATCH void func_801F3A78(void) {
    SYS_DISPATCH_BYTE(D_801F6258, SP_REF(u8*, 0x44)[0x2]);
}
