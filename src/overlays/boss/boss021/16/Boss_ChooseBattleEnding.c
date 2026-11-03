#include "boss021_16.h"

/* func_800C1C18 */
MATCH void Boss_ChooseBattleEnding(void) {
    if BATTLE_IS_VICTORY () {
        g_ScriptVars = 0x0A;
        func_801DDED8();
    } else {
        func_801DDF00();
    }
}
