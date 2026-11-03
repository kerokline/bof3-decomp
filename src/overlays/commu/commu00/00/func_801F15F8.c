#include "commu00_00.h"

MATCH s32 func_801F15F8(u8* active_ui) {
    FAIRY_VILLAGE_ACTIVE_UI = active_ui;
    D_801448EB              = 25;
    D_801448ED              = active_ui[5];
    Game_SetScriptActive();
    return 0;
}
