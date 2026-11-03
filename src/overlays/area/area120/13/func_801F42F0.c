#include "area120_13.h"

MATCH void func_801F42F0(void) {
    MESSAGE_REQUEST_CLEAR();
    if (MENU_SELECTION_ARMED()) {
        g_ScriptVars = 0x14;
    } else {
        g_ScriptVars = 0xA;
    }
}
