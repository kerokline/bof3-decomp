#include "engine/slus/slus.h"

/* stores the given byte at D_8018E98C.
 */
/* func_801737B4 */
MATCH void SsSetAutoKeyOffMode(short mode) {
    D_8018E98C = mode;
}
