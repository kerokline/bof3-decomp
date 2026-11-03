#include "boss036_16.h"

/* func_800C1DB8 */
MATCH void Boss_ChooseBattleEnding(void) {
    if BATTLE_IS_VICTORY () {
        D_80146875 = 8;
        func_801DDED8();
    } else {
        func_801DDF00();
    }
}
