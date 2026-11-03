#include "area049_14.h"

MATCH void func_801F2C80(void) {
    s32* var_s0;

    var_s0 = (s32*)&g_SceneEventFlags;
    var_s0 = (s32*)&g_SceneEventFlags;
    SYS_ClearFlag(g_SceneEventFlags, 2U);
    SYS_SetFlag(g_SceneEventFlags, 3U);
}
