#include "area030_04.h"

/* Dispatches the AREA030 battle-intro scratchpad state byte through
 * the overlay's jump table. */
MATCH void func_801D20C8(void) {
    D_801E1D20[FISHING_STATE->handler_index_01]();
}
