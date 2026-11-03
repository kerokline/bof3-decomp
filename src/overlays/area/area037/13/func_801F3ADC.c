#include "area037_13.h"

MATCH s32 func_801F3ADC(void) {
    /* FAKE: retail materializes the action code in v1. */
    MATCH_REG(s32, action, "v1");

    Game_SetScriptActive();
    action     = 4;
    D_801448EB = action;
    action     = 13;
    D_801448ED = action;
    return 0;
}
