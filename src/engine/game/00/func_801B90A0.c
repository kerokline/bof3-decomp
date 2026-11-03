#include "game_00.h"

MATCH void func_801B90A0(void) {
    SND_PlayCue(EMI_CUE_ID(1, 7));
    func_801A0048(g_SpadWork->x.part.integer, g_SpadWork->y.part.integer);
    g_SpadWork->vz = 0;
    Actor_RequestScript(g_SpadWork->direction_08);
    g_SpadWork->unk_03 = 1;
}
