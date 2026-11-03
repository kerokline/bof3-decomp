#include "sys/gameui.h"

/* One definition shared by the ten world04 area request overlays
 * (emi/world04/area176/13 through emi/world04/area185/13) at 0x801F2D44;
 * every change here must verify every member address. */
MATCH void func_801F2D44(void) {
    if (MENU_SELECTION_IDLE()) {
        MESSAGE_REQUEST_CLEAR();
        D_801F294D = 0;
    } else {
        g_MessageRequest = 0x5F;
        D_801F294C++;
    }
}
