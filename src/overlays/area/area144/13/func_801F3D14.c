#include "area144_13.h"

MATCH void func_801F3D14(void) {
    MESSAGE_REQUEST_CLEAR();
    if (MENU_SELECTION_IDLE()) {
        g_ScriptVars = 5;
        func_801BE1B0(6);
        D_80146874 = 7;
        D_80146875 = 0x14;
    } else {
        func_801BE1B0(5);
    }
}
