#include "engine/slus/slus.h"

/* decrements D_801490A3 when the D_801490BA countdown is 2, and steps the
 * countdown up by two otherwise.
 */
MATCH void func_80151A48(void) {
    s8 value;

    value = D_801490BA[0];
    if (value == 2) {
        D_801490A3 = D_801490A3 - 1;
    } else {
        D_801490BA[0] = value + 2;
    }
}
