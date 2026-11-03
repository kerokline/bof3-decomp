#include "sys/gameui.h"

/* One definition shared by the ten world04 area request overlays
 * (emi/world04/area176/13 through emi/world04/area185/13) at 0x801F2FB4;
 * every change here must verify every member address. */
MATCH void func_801F2FB4(void) {
    if (MENU_SELECTION_IDLE()) {
        g_MessageRequest = 0x89;
    } else {
        g_MessageRequest = 0x88;
        D_801F294C       = 2;
    }
}
