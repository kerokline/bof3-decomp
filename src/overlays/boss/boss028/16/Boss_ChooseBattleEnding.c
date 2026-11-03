#include "boss028_16.h"

/* func_800C1B80 */
MATCH void Boss_ChooseBattleEnding(void) {
    if BATTLE_IS_VICTORY () {
        g_ScriptVars = 30;
        func_801DDED8();
    } else {
        func_801DDF00();
    }
}
