#include "battle_03.h"

/* func_801DBB78 */
MATCH u32 Battle_ApplyDamage(u8 attacker, u8 target) {
    s32 damage;

    if (BATTLER_IS_PLAYER(target)) {
        g_BattlePartyBattlers[target].unk_120 = 0x11;
    } else {
        ENEMY_COMBATANT(target).target_flags_FC = 0x11;
    }
    damage = Battle_CalcDamage(attacker, target, 0xFFFF);
    if (BATTLER_IS_PLAYER(target)) {
        if (g_BattlePartyBattlers[target].flags_124.value & COMBATANT_FLAG_HURT_REACTION) {
            damage = g_BattlePartyBattlers[target].stats.current_hp;
            func_801DE560(1, 0, 0, 0x1E, (u32)D_801EB075);
            g_BattleMessageState = 1;
            g_BattlePartyBattlers[target].flags_124.value &= ~0x100;
        }
        if (damage > 0) {
            if (damage < g_BattlePartyBattlers[target].stats.current_hp) {
                g_BattlePartyBattlers[target].stats.current_hp -= damage;
            } else {
                if (damage - g_BattlePartyBattlers[target].stats.current_hp <
                    g_BattlePartyBattlers[target].stats.current_willpower) {
                    if (!(g_BattlePartyBattlers[target].flags_128.value & 1) &&
                        !(g_BattlePartyBattlers[target].flags_128.value & 2)) {
                        g_BattlePartyBattlers[target].flags_124.value |= 4;
                    }
                }
                g_BattlePartyBattlers[target].stats.current_hp = 0;
            }
        } else if (g_BattlePartyBattlers[target].stats.current_hp - damage <
                   g_BattlePartyBattlers[target].stats.max_hp) {
            g_BattlePartyBattlers[target].stats.current_hp -= damage;
        } else {
            g_BattlePartyBattlers[target].stats.current_hp = g_BattlePartyBattlers[target].stats.max_hp;
            g_BattlePartyBattlers[target].unk_120 |= 4;
        }
    } else if (ENEMY_COMBATANT(target).hp_94 != 0xFFFF) {
        if ((ENEMY_COMBATANT(target).flags_100 & COMBATANT_FLAG_HURT_REACTION) &&
            ENEMY_COMBATANT(target).hp_94 <= 0x7FFF) {
            damage = ENEMY_COMBATANT(target).hp_94;
            func_801DE560(1, 0, 0, 0x1E, (u32)D_801EB075);
            g_BattleMessageState = 1;
            ENEMY_COMBATANT(target).flags_100 &= ~0x100;
        }
        if (damage > 0) {
            if (damage < ENEMY_COMBATANT(target).hp_94) {
                ENEMY_COMBATANT(target).hp_94 -= damage;
            } else {
                ENEMY_COMBATANT(target).hp_94 = 0;
            }
        } else if (ENEMY_COMBATANT(target).hp_94 - damage < ENEMY_COMBATANT(target).cell_A0.max_hp) {
            ENEMY_COMBATANT(target).hp_94 -= damage;
        } else {
            ENEMY_COMBATANT(target).hp_94 = ENEMY_COMBATANT(target).cell_A0.max_hp;
            ENEMY_COMBATANT(target).target_flags_FC |= 4;
        }
    }
    if (attacker < 3 && g_BattlePartyBattlers[attacker].unk_13A[2] == 5 && damage != 0) {
        if (g_BattlePartyBattlers[attacker].stats.weapon == WEAPON_SLEEP_SHELLS && !func_800A3DF8(attacker, target)) {
            func_800A31E0(target, 0x40);
        }
        if (g_BattlePartyBattlers[attacker].stats.weapon == WEAPON_FLASH_SHELLS && !func_800A3DF8(attacker, target)) {
            func_800A31E0(target, 8);
        }
        if (g_BattlePartyBattlers[attacker].stats.weapon == WEAPON_GAS_SHELLS && !func_800A3DF8(attacker, target)) {
            func_800A31E0(target, 0x20);
        }
    }
    return (s16)damage;
}
