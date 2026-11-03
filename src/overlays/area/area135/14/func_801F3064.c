#include "area135_14.h"

/* Dispatch the scratchpad state byte through the overlay's handler table. */
MATCH void func_801F3064(void) {
    SYS_DISPATCH_BYTE(D_801F6200, SP_REF(u8*, 0x44)[0x1]);
}
