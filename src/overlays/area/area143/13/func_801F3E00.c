#include "area143_13.h"

MATCH s32 func_801F3E00(void) {
    Game_SetScriptActive();
    D_801448EB = 4;
    D_801448ED = 0xF;
    if (g_AreaSceneMode == 0) {
        g_AreaSceneMode = 1;
        D_801448EC      = 5;
    }
    return 0;
}
