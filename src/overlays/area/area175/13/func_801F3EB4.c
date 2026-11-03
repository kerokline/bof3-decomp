#include "area175_13.h"

MATCH void func_801F3EB4(void) {
    if (MENU_SELECTION_IDLE()) {
        MESSAGE_REQUEST_CLEAR();
        D_801F2944 = 0;
    } else if (D_801490C7 == 1) {
        MESSAGE_REQUEST_CLEAR();
        D_801F2944 = 1;
    } else {
        g_MessageRequest                     = 0x2A1;
        FIELD(u8, g_ScriptWorkRecord, 0x7Au) = 0xFF;
    }
}
