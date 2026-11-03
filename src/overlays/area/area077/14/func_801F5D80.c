#include "area077_14.h"

MATCH void func_801F5D80(void) {
    g_AreaViewRefreshCount = 2;
    g_AreaViewOffsetY      = (u16)g_AreaViewOffsetY - 0x14;
    SND_PlayCue(EMI_CUE_ID(2, 0));
}
