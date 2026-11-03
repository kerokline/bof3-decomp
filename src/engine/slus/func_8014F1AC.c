#include "engine/slus/slus.h"

/* calls GFX_RunBlackFade with delta 0x200, semi-transparency 1 and order 0.
 */
MATCH void func_8014F1AC(void) {
    GFX_RunBlackFade(0x200, 1, 0);
}
