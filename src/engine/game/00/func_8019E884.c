#include "game_00.h"

MATCH void func_8019E884(void) {
    Actor* work;
    s32    add;
    s16    dist;

    add                        = g_SpadWork->vz + g_SpadWork->gravity;
    g_SpadWork->vz             = add;
    g_SpadWork->z.part.integer = (u16)(g_SpadWork->z.part.integer + add);
    func_8014D978();
    work = g_SpadWork;
    dist = Area_SampleHeight(work->x.fixed, work->y.fixed);
    if (work->z.part.integer < dist) {
        Actor_Clear();
        return;
    }
    Area_SetDrawMode();
}
