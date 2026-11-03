#include "area168_13.h"

MATCH void func_801F4980(void) {
    MESSAGE_REQUEST_CLEAR();
    if (MENU_SELECTION_IDLE()) {
        Game_SetScriptActive();
        D_801448EB = 0x3B;
        D_801448EC = 0xA;
    }
}
