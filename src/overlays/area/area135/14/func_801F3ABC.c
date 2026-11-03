#include "area135_14.h"

MATCH void func_801F3ABC(void) {
    if (SYS_TestFlag(&g_SceneEventFlags, 0x2A)) {
        g_SpadWork->z.fixed  = -0x180;
        g_SpadWork->state_02 = 3;
    } else {
        g_SpadWork->z.fixed = -0x90;
        g_SpadWork->state_02++;
    }
    func_801F3CA8();
}
