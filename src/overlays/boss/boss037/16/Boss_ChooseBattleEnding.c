#include "boss037_16.h"

/* func_800C193C */
MATCH void Boss_ChooseBattleEnding(void) {
    if BATTLE_IS_VICTORY () {
        D_80146875 = 28;
        func_801DDED8();
    } else {
        func_801DDF00();
    }
}
