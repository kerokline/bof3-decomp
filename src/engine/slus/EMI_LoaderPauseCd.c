#include "engine/slus/slus.h"

/* pauses the CD reader and flags completion.
 */
/* func_80162F34 */
MATCH void EMI_LoaderPauseCd(void) {
    if (CdSync(1, D_80146498) != CdlNoIntr) {
        D_8014648C = 0;
        if (CdPause() != 0) {
            D_8014648A = 7;
        }
    }
}
