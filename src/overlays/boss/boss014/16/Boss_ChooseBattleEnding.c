#include "boss014_16.h"

/* func_800C1A28 */
MATCH void Boss_ChooseBattleEnding(void) {
    if BATTLE_IS_VICTORY () {
        g_ScriptVars[0] = 0x0C;
        func_801DDED8();
    } else {
        func_801DDF00();
    }
}
