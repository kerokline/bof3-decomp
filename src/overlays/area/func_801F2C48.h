#include "sys/gameui.h"

/* One definition shared by the ten world04 area request overlays
 * (emi/world04/area176/13 through emi/world04/area185/13) at 0x801F2C48;
 * every change here must verify every member address. */
MATCH void func_801F2C48(void) {
    MESSAGE_REQUEST_CLEAR();
    if (MENU_SELECTION_IDLE()) {
        g_ScriptVars[0]      = 0x28;
        g_SceneState.step_05 = 0x15;
    } else {
        g_ScriptVars[0]      = 0x32;
        g_SceneState.step_05 = 0x19;
    }
}
