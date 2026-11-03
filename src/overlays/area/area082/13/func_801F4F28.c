#include "area082_13.h"

MATCH void func_801F4F28(void) {
    D_8014933A = 0;
    func_801F5428(0x10001805);
    if (g_ScriptVars[0] == 0x35) {
        g_SpadWork->state_02++;
        SND_PlayCue(0x201);
    }
}
