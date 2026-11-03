#include "engine/slus/slus.h"

/* calls GFX_RunBlackFade with delta 0x2000, semi-transparency 1 and order 0.
 */
MATCH void func_8014EE40(void) {
    GFX_RunBlackFade(0x2000, 1, 0);
}
