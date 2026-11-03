#include "area008_13.h"

MATCH void func_801F3010(void) {
    volatile Actor* previous;

    g_SpadWork->unk_09 = 0;
    if ((g_ScriptVars[3] & 0x80u) != 0u) {
        g_SpadWork->unk_01 = 9;
        return;
    }
    previous                  = g_SpadWork;
    WORLD00_AREA008_STATE_PTR = (volatile Actor*)&g_BattlePartyBattlers[1];
    g_SpadWork                = (u8*)&g_BattlePartyBattlers[1];
    D_801460E8 |= 0x40;
    SND_PlayCue(EMI_CUE_ID(2, 14));
    Actor_SelectScript(0x57);
    g_SpadWork       = previous;
    previous->unk_01 = 7;
}
