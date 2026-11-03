#include "commu00_00.h"

MATCH s32 func_801F1484(u8* active_ui) {
    FAIRY_VILLAGE_ACTIVE_UI = active_ui;
    D_801448EB              = 22;
    D_801448ED              = active_ui[5];
    Game_SetScriptActive();
    return 0;
}
