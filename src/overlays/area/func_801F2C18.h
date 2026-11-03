#include "sys/gameui.h"

/* One definition shared by the ten world04 area request overlays
 * (emi/world04/area176/13 through emi/world04/area185/13) at 0x801F2C18;
 * every change here must verify every member address. */
MATCH void func_801F2C18(void) {
    MESSAGE_REQUEST_CLEAR();
    if (MENU_SELECTION_ARMED()) {
        D_80146875 = 2;
    } else {
        D_80146875 = 3;
    }
}
