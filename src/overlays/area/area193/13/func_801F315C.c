#include "area193_13.h"

MATCH s32 func_801F315C(s32 entry_x, s32 entry_y) {
    if ((entry_x == 0x18000) || (entry_y == 0x18000) || (entry_x == 0x338000) || (entry_y == 0x338000)) {
        Game_SetScriptActive();
        D_801448EB = 0x39;
        D_801448EC = 0xA;
        return 1;
    }
    return 0;
}
