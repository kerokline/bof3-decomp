#include "sys/gameui.h"

/* One definition shared by the ten world04 area request overlays
 * (emi/world04/area176/13 through emi/world04/area185/13) at 0x801F3078;
 * every change here must verify every member address. */
MATCH void func_801F3078(void) {
    if (MENU_SELECTION_IDLE()) {
        g_MessageRequest = 0x78;
        D_801F294D       = 0xB;
    } else {
        g_MessageRequest = 0x72;
        D_801F294D       = 0xC;
    }
    D_801F294E = 0;
}
