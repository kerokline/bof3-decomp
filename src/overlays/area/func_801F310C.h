#include "sys/gameui.h"

/* One definition shared by the ten world04 area request overlays
 * (emi/world04/area176/13 through emi/world04/area185/13) at 0x801F310C;
 * every change here must verify every member address. */
MATCH void func_801F310C(void) {
    if (MENU_SELECTION_IDLE()) {
        D_801F294C = 1;
    } else {
        D_801F294C = 2;
    }
    g_MessageRequest = 0xEF;
}
