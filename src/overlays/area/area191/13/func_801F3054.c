#include "area191_13.h"

MATCH void func_801F3054(void) {
    MESSAGE_REQUEST_CLEAR();
    if (D_801490C7 == 1) {
        Game_SetScriptActive();
        D_801448EB = 0x35;
        D_801448EC = 0x1E;
    } else if (D_801490C7 == 2) {
        Game_SetScriptActive();
        D_80146874 = 1;
        D_80146875 = 0x14;
    }
}
