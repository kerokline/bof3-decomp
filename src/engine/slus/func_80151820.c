#include "engine/slus/slus.h"

/* clears D_801490A0 when D_80148333 is 2.
 */
MATCH void func_80151820(void) {
    if (D_80148333[0] == 2) {
        D_801490A0.state_00 = 0;
    }
}
