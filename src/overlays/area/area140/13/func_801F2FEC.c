#include "area140_13.h"

MATCH void func_801F2FEC(void) {
    if (SYS_TestFlag(g_SceneEventFlags, 0x54) != 0) {
        if (g_GameStateIndex == 0) {
            SND_PlayCue(EMI_CUE_ID(2, 0));
        }
        g_SpadWork->state_02 = 2;
    }
    func_801F3050();
}
