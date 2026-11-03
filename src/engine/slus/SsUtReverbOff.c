#include "engine/slus/slus.h"

/* turns the SPU reverb unit off.
 */
/* func_8016F698 */
MATCH void SsUtReverbOff(void) {
    SpuSetReverb(SPU_OFF);
}
