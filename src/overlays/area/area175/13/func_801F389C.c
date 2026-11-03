#include "area175_13.h"

MATCH void func_801F389C(void) {
    MESSAGE_REQUEST_CLEAR();
    if (MENU_SELECTION_IDLE()) {
        g_ScriptVars[0]      = 0x28;
        g_SceneState.step_05 = 0x15;
    } else {
        g_ScriptVars[0]      = 0x32;
        g_SceneState.step_05 = 0x19;
    }
}
