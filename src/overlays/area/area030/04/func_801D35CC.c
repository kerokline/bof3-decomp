#include "area030_04.h"

/* When the record pointer left the D_80144124 slot and the state
 * byte is below 4, resets the work area; otherwise dispatches the scratch
 * record byte at +1 through the overlay's jump table. */
MATCH void func_801D35CC(void) {
    FishingState* record;

    record = FISHING_STATE;
    if (((u8*)record != &D_80144124) && (D_80144125 < 4u)) {
        Actor_Clear();
        return;
    }
    D_801E1F44[FISHING_STATE->handler_index_01]();
}
