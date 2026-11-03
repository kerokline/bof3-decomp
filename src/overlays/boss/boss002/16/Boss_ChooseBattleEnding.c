#include "boss002_16.h"

/* func_800C1DD4 */
MATCH void Boss_ChooseBattleEnding(void) {
    if (FIELD(u32, &g_BattleResult, 0) & 6) {
        func_800AC934(0);
        g_ScriptVars[0] = 0x24;
        g_SndBgmId      = 0x1B;
        func_801DDED8();
    } else {
        func_801DDF00();
    }
}
