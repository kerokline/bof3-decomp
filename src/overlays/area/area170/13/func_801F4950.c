#include "area170_13.h"

MATCH void func_801F4950(void) {
    MESSAGE_REQUEST_CLEAR();
    if (MENU_SELECTION_IDLE()) {
        Game_SetScriptActive();
        D_801448EB = 0x25;
        D_801448EC = 5;
    }
}
