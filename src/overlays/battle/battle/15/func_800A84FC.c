#include "battle_15.h"

MATCH void func_800A84FC(void) {
    if (D_801463C2 == 0) {
        g_BattleState |= BATTLE_STATE_EFFECT_PLAYING;
        func_801E5988();
    }
}
