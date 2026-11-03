#include "sisyou_00.h"

/* Panel-lock flag owned by the main executable. */

MATCH void func_801D2614(void) {
    s32 step;

    if (SYS_TestFlag(D_8014554F, D_801448ED) != 0) {
        step = 5;
    } else if (D_801448ED == 9) {
        Message_StartAreaMessage(0x2E);
        g_GameStateIndex = GAME_REQUEST_MESSAGE;
        step             = 6;
    } else {
        step = 1;
    }
    g_MasterStep = step;
}
