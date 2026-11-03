#include "area175_13.h"

MATCH void func_801F389C(void) {
    MESSAGE_REQUEST_CLEAR();
    if (MENU_SELECTION_IDLE()) {
        g_ScriptVars = 0x28;
        D_80146875   = 0x15;
    } else {
        g_ScriptVars = 0x32;
        D_80146875   = 0x19;
    }
}
