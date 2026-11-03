#include "boss029_16.h"

/* func_800C1930 */
MATCH void Boss_ChooseBattleEnding(void) {
    if BATTLE_IS_VICTORY () {
        D_80146875 = 0x1C;
        func_801DDED8();
        g_SndBgmId = 0x62;
    } else {
        func_801DDF00();
    }
}
