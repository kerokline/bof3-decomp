#include "commu00_00.h"

MATCH s32 func_801F1538(u8* active_ui) {
    D_801448EB              = 23;
    FAIRY_VILLAGE_ACTIVE_UI = active_ui;
    D_801448ED              = 3;
    Game_SetScriptActive();
    return 0;
}
