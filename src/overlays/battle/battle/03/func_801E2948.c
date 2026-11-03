#include "battle_03.h"

MATCH void func_801E2948(s8 enemy_index) {
    if (!(((RANDOM_MASK(7)) < 3) || (BATTLE_GLOBAL_BYTE_62F3 == 1u))) {
        (*(u8*)&g_BattleTargetSelector) = Battle_PickRandomTarget((u8)(enemy_index + 3));
    } else {
        (*(u8*)&g_BattleTargetSelector) = func_801E2E30();
    }
}
