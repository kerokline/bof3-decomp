#include "area145_14.h"

MATCH void func_801F3C90(void) {
    MESSAGE_REQUEST_CLEAR();
    if (MENU_SELECTION_ARMED()) {
        g_ScriptVars = 8;
    } else {
        g_ScriptVars = 0xA;
        D_80146874   = 3;
        D_80146875   = 0xA;
    }
}
