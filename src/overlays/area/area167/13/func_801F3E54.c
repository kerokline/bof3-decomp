#include "area167_13.h"

MATCH void func_801F3E54(void) {
    MESSAGE_REQUEST_CLEAR();
    if (MENU_SELECTION_IDLE()) {
        Game_SetScriptActive();
        D_80146867 = 0x60;
        D_801448EB = 0x20;
        D_801448EC = 0xA;
    }
}
