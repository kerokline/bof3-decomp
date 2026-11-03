/* dispatches to the mode handler selected by the flag.
 */
#include "engine/slus/slus.h"

/* func_80163010 */
MATCH void EMI_LoaderService(void) {
    if (g_EmiServiceMode == 1) {
        EMI_LoaderServiceStream();
    } else if (g_EmiServiceMode == 2) {
        SND_ServiceXa();
    }
}
