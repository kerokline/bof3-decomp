#include "area140_13.h"

MATCH void func_801F2F7C(void) {
    Actor* work;

    work = (Actor*)g_SpadWork;
    work->unk_30 += 0x20;
    if ((s16)work->unk_30 >= 0) {
        if (g_GameStateIndex == 0) {
            SND_PlayCue(EMI_CUE_ID(2, 1));
        }
        ((Actor*)g_SpadWork)->state_02 = 1;
    }
    func_801F3050();
}
