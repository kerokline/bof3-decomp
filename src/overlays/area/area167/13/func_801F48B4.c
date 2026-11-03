#include "area167_13.h"

MATCH u8 func_801F48B4(s32 x, s32 y) {
    if ((y >> 16) == 0x66 && (u32)((x >> 16) - 0x14) < 3) {
        Game_SetScriptActive();
        D_801448EB = 0x20;
        D_801448EC = 0;
        return 1;
    }
    return 0;
}
