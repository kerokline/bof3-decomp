#include "battle_03.h"

MATCH void func_801DCEF8(u32 battler_index) {
    s32 value;

    battler_index &= BYTE_MASK;
    if (BATTLER_IS_PLAYER(battler_index)) {
        if (HAS_STATUS(g_BattlePartyBattlers[battler_index], STATUS_POISONED)) {
            value = (g_BattlePartyBattlers[battler_index].stats.current_hp + 5) / 10;
            g_BattlePartyBattlers[battler_index].hp_change = value;
        }
    } else {
        if ((ENEMY_COMBATANT(battler_index).status_82 & STATUS_POISONED) != 0u) {
            value                                    = (ENEMY_COMBATANT(battler_index).hp_94 + 5) / 10;
            ENEMY_COMBATANT(battler_index).damage_F8 = value;
        }
    }
}
