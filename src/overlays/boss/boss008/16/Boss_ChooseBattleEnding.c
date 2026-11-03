#include "boss008_16.h"

/* func_800C1FDC */
MATCH void Boss_ChooseBattleEnding(void) {
    if BATTLE_IS_VICTORY () {
        g_ScriptVars[0] = 0x11;
        func_801DDED8();
    } else {
        func_801DDF00();
    }
}
