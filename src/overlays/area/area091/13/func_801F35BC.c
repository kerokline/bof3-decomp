#include "area091_13.h"

MATCH s32 func_801F35BC(void) {
    /* FAKE: retail reads Game_SetScriptActive as s32(void). */
    ((s32 (*)(void))Game_SetScriptActive)();
    D_801448EB = 4;
    D_801448ED = 0x10;
    return 0;
}
