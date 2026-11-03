#include "area199_13.h"

MATCH void func_801F2C7C(void) {
    s32 x;

    x                   = g_SpadWork->x.fixed - ((g_FrameCount & 3) < 1);
    g_SpadWork->x.fixed = x;
    func_801F2E80(x);
}
