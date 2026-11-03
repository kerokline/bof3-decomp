#include "area192_13.h"

MATCH void func_801F2DBC(void) {
    MESSAGE_REQUEST_CLEAR();
    if (D_801490C7 == 1) {
        Game_SetScriptActive();
        D_801448EB = 0x36;
        D_801448EC = 0x1E;
    } else if (D_801490C7 == 2) {
        Game_SetScriptActive();
        D_80146874 = 1;
        D_80146875 = 0x14;
    }
}
