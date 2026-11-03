#include "area168_13.h"

MATCH void func_801F38A4(void) {
    Actor* work;

    work = g_SpadWork;
    work->unk_30 -= 0x10;
    if ((s16)work->unk_30 <= 0) {
        if (g_GameStateIndex == 0) {
            SND_PlayCue(EMI_CUE_ID(2, 1));
        }
        g_SpadWork->state_02 = 1;
    }
    Area_Update();
}
