#include "boss050_16.h"

/* func_800C1948 */
MATCH void Boss_ChooseBattleEnding(void) {
    if BATTLE_IS_VICTORY () {
        D_80146875 = 0x10;
        func_801DDED8();
        g_SndBgmId = 0x8C;
    } else {
        func_801DDF00();
    }
}
