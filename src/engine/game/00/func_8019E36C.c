#include "game_00.h"

MATCH void func_8019E36C(void) {
    s32 add;
    s16 dist;
    s16 limit;

    add                        = g_SpadWork->vz + g_SpadWork->gravity;
    g_SpadWork->vz             = add;
    g_SpadWork->z.part.integer = (u16)(g_SpadWork->z.part.integer + add);
    func_8014D978();
    dist  = Area_SampleHeight(g_SpadWork->x.fixed, g_SpadWork->y.fixed);
    limit = g_SpadWork->z.part.integer;
    if (dist >= limit) {
        Actor_Clear();
        return;
    }
    if ((dist + 0x100 < limit) || (g_FrameCount & 1)) {
        Area_SetDrawMode();
    }
}
