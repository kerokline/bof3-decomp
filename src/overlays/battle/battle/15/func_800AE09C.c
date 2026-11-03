#include "battle_15.h"

/* Main-executable battle-selection cell consumed by the countdown arm. */

MATCH void func_800AE09C(void) {
    u8 count;

    count = SP_REF(u8*, 0x44u)[9];
    if (count == 0) {
        func_800A9820(g_BattleTargetSelector);
        g_BattleState |= BATTLE_STATE_EFFECT_PLAYING;
        func_801E5988();
    } else {
        SP_REF(u8*, 0x44u)[9] = count - 1;
    }
}
