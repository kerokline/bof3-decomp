#include "engine/slus/slus.h"

/* calls GFX_RunWhiteFade with delta 0x800, semi-transparency 1 and order 0.
 */
MATCH void func_8014EF30(void) {
    GFX_RunWhiteFade(0x800, 1, 0);
}
