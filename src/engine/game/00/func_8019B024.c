#include "game_00.h"

MATCH void func_8019B024(void) {
    Actor* work;
    s16    dist;
    s16    counter;
    s32    diff;

    dist    = Area_SampleHeight(g_SpadWork->x.fixed, g_SpadWork->y.fixed);
    counter = g_SpadWork->z.part.integer;
    if ((counter >= dist + 0x80) || (counter < dist) || (g_SpadWork->flags_00 & ACTOR_FLAG_OFFSCREEN)) {
        work = g_SpadWork;
        work->unk_01++;
        SND_PlayCue(EMI_CUE_ID(1, 6));
    }
    g_SpadWork->z.fixed += g_SpadWork->vz;
    diff           = g_SpadWork->vz - g_SpadWork->gravity;
    g_SpadWork->vz = diff;
    func_8014D978();
    Area_SetDrawMode();
}
