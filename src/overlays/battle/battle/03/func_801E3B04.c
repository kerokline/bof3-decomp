#include "battle_03.h"

MATCH void func_801E3B04(void) {
    if (func_801E30F8() != 0u) {
        func_800A9820(g_BattleTargetSelector);
        func_801E5704();
        g_BattleState |= BATTLE_STATE_EFFECT_PLAYING;
        func_801E567C();
    }
}
