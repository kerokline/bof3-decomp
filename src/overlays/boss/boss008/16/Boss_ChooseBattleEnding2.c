#include "boss008_16.h"

/* func_800C20C8 */
MATCH void Boss_ChooseBattleEnding2(void) {
    if BATTLE_IS_VICTORY () {
        g_ScriptVars[0] = 0x20;
        func_801DDED8();
    } else {
        func_801DDF00();
    }
}
