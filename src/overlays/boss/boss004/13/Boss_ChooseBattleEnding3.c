#include "boss004_13.h"

/* func_800C2524 */
MATCH void Boss_ChooseBattleEnding3(void) {
    if (g_BattleResult & BATTLE_RESULT_DEFEAT) {
        g_BattlePartyOrder = 7;
        g_BattleOptions |= 0x80;
        func_801DDF28();
        D_80146875 = 0x32;
    } else {
        u8* step;

        step = &D_80146875;
        (*step)++;
        func_801DDF28();
    }
}
