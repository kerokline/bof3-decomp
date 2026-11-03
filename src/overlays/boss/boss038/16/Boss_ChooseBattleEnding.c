#include "boss038_16.h"

/* func_800C1BBC */
MATCH void Boss_ChooseBattleEnding(void) {
    if BATTLE_IS_VICTORY () {
        g_SceneState.step_05 = 5;
        func_801DDED8();
    } else {
        func_801DDF00();
    }
}
