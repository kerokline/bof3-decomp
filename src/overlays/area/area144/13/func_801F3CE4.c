#include "area144_13.h"

MATCH void func_801F3CE4(void) {
    MESSAGE_REQUEST_CLEAR();
    if (MENU_SELECTION_ARMED()) {
        g_ScriptVars[0] = 0x23;
    } else {
        g_ScriptVars[0] = 0x1E;
    }
}
