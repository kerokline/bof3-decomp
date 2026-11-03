#include "boss008_16.h"

/* func_800C22C0 */
MATCH void Boss_ChooseBattleEnding4(void) {
    if BATTLE_IS_VICTORY () {
        g_ScriptVars[0] = 0x44;
        func_801DDED8();
    } else {
        func_801DDF00();
    }
}
