#include "game_00.h"

MATCH void func_8019BFD4(void) {
    s32 neg;

    g_AreaCameraStep       = 0x40;
    g_AreaCameraMoving     = 1;
    g_AreaScrollTargetX    = D_80145EC4;
    g_AreaScrollTargetY    = D_80145EC8;
    neg                    = -g_AreaCameraHeightStep;
    g_AreaCameraHeightStep = neg;
}
