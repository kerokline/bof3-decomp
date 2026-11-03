#include "area115_13.h"

MATCH void func_801F32A4(void) {
    Actor* work;
    u8     step;

    Actor_CenterOnScreen();
    if (g_GameEntryState != 1) {
        work = g_SpadWork;
        step = work->unk_0B;
        if (step == work->unk_07 && g_GameStateIndex != 5) {
            if (step != 1) {
                goto tail; /* no arming stores: run the step only */
            }
            if (work->unk_18 == g_GameContextSeed) {
                goto tail; /* no arming stores: run the step only */
            }
        }
        g_SpadWork->unk_48 = 2;
        g_SpadWork->unk_09 = 8;
        g_SpadWork->unk_01 = 4;
    }
tail:
    Area_AddActor();
}
