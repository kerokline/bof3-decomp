#include "area078_13.h"

MATCH void func_801F2C04(void) {
    s32 bit;

    g_MessageRequest = 0xFFFF;
    switch (D_801490C7) {
        case 0:
            bit = 0x16;
            break;
        case 1:
            bit = 0x17;
            break;
        default:
            return;
    }
    g_ScriptVars = 0x1E;
    SYS_SetFlag(g_SceneFlags, bit);
}
