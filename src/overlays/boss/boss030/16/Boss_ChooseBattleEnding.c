#include "boss030_16.h"

/* func_800C1A1C */
MATCH void Boss_ChooseBattleEnding(void) {
    u8* visit_count;

    if BATTLE_IS_VICTORY () {
        visit_count = &g_ScriptVars;
        (*visit_count)++;
        D_80146875 = 0xC;
        func_801DDED8();
        g_SndBgmId = 0x5A;
    } else {
        func_801DDF00();
    }
}
