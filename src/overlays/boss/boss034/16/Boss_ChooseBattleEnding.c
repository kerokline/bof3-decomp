#include "boss034_16.h"

/* func_800C2380 */
MATCH void Boss_ChooseBattleEnding(void) {
    if BATTLE_IS_VICTORY () {
        D_80146875 = 5;
        func_801DDED8();
    } else {
        func_801DDF00();
    }
}
