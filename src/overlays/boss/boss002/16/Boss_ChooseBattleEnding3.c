#include "boss002_16.h"

/* func_800C1F48 */
MATCH void Boss_ChooseBattleEnding3(void) {
    if (g_BattleResult & BATTLE_RESULT_VICTORY) {
        D_80146875 = 5;
        func_801DDED8();
    } else {
        func_801DDF00();
    }
}
