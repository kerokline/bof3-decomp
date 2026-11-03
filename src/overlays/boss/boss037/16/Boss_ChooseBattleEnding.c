#include "boss037_16.h"

/* func_800C193C */
MATCH void Boss_ChooseBattleEnding(void) {
    if BATTLE_IS_VICTORY () {
        g_SceneState.step_05 = 28;
        func_801DDED8();
    } else {
        func_801DDF00();
    }
}
