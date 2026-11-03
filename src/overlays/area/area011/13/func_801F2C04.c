#include "area011_13.h"

MATCH void func_801F2C04(void) {
    if ((s16)g_AreaViewOffsetZ >= -0x13FF) {
        g_AreaViewOffsetZ = (s16)g_AreaViewOffsetZ - 0xA0;
    }
    g_AreaViewRefreshCount = 2;
}
