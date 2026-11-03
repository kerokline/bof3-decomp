#include "boss015_16.h"

/* func_800C1930 */
MATCH void Boss_ChooseBattleEnding(void) {
    if BATTLE_IS_VICTORY () {
        g_ScriptVars = 0x4B;
        func_801DDED8();
    } else {
        func_801DDF00();
    }
}
