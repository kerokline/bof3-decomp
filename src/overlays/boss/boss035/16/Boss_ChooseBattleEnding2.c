#include "boss035_16.h"

MATCH void Boss_ChooseBattleEnding2(void) {
    if BATTLE_IS_VICTORY () {
        D_80146875 = 5;
        func_801DDED8();
    } else {
        func_801DDF00();
    }
}
