#include "sisyou_00.h"

/* func_801D0C18 */
MATCH void Master_ResetPanel(void) {
    g_MasterStep         = 0;
    g_MasterSubStep      = 0;
    g_MasterPanelLock    = 0;
    D_801D4288           = 0;
    g_MasterScrollOffset = 0;
}
