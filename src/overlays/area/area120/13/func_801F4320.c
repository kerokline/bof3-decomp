#include "area120_13.h"

MATCH void func_801F4320(void) {
    MESSAGE_REQUEST_CLEAR();
    if (MENU_SELECTION_ARMED()) {
        g_ScriptVars[0] = 0x1E;
    } else {
        g_ScriptVars[0] = 0x28;
    }
}
