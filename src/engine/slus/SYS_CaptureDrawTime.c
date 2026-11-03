#include "engine/slus/slus.h"

/* captures the current vertical-blank counter for the boot frame.
 */
/* func_8014B17C */
MATCH void SYS_CaptureDrawTime(void) {
    D_80143EFC = VSync(1);
}
