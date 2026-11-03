#include "engine/slus/slus.h"

/* dispatches through the two-entry callback table on D_801490A3.
 */
MATCH void func_80151D3C(void) {
    void (*table[2])(void) = {func_80151D8C, func_80151DCC};

    table[D_801490A3]();
}
