#include "battle_15.h"

/* A party actor's fatigue rises below 5 and the party stats are rebuilt; an enemy actor loses a tenth of its
 * encounter HP from its max HP. Then, unless the target resists, the HP change leaves the target at 1 HP.
 */
MATCH void func_800A0EC4(void) {
    Character* member_chr;
    s32        record_index;
    u8         i;
    Character* cell;
    u8         timer;
    u16        max_hp;
    u16        tenth;
    u16        value;

    if (g_Battle.active_battler < 3) {
        record_index = g_Game.members[g_Battle.active_battler].character_index;
        timer        = g_Characters[record_index].fatigue;
        if (timer < 5) {
            g_Characters[record_index].fatigue = timer + 1;
            g_Game.members[g_Battle.active_battler].chr.fatigue += 1;
        }
        Char_RebuildStats(&g_Characters[g_Game.members[g_Battle.active_battler].character_index]);
        for (i = 0; i < g_Battle.party_count; i++) {
            member_chr                       = &g_Game.members[i].chr;
            cell                             = &g_Characters[g_Game.members[i].character_index];
            member_chr->equip.weapon         = cell->equip.weapon;
            member_chr->equip.shield         = cell->equip.shield;
            member_chr->equip.helmet         = cell->equip.helmet;
            member_chr->equip.armor          = cell->equip.armor;
            member_chr->equip.accessories[0] = cell->equip.accessories[0];
            member_chr->equip.accessories[1] = cell->equip.accessories[1];
            *(Cpy32u*)&member_chr->base      = *(Cpy32u*)&cell->stats;
        }
        Battle_ApplyFormationStats();
        for (i = 0; i < g_Battle.party_count; i++) {
            *(Cpy32u*)&g_Game.members[i].chr.stats = *(Cpy32u*)&g_Game.members[i].chr.base;
        }
        func_800A4458();
        for (i = 0; i < g_Battle.party_count; i++) {
            Battle_RescaleStats(i);
        }
    } else {
        max_hp = ENEMY_COMBATANT(g_Battle.active_battler).stats.max_hp;
        if (max_hp != 0xFFFF) {
            tenth = ENCOUNTER_ENEMIES[ENEMY_COMBATANT(g_Battle.active_battler).type].hp / 10;
            if (tenth < max_hp) {
                ENEMY_COMBATANT(g_Battle.active_battler).stats.max_hp = max_hp - tenth;
                ENEMY_COMBATANT(g_Battle.active_battler).base.max_hp -= ENCOUNTER_ENEMIES[ENEMY_COMBATANT(g_Battle.active_battler).type].hp / 10;
                if (ENEMY_COMBATANT(g_Battle.active_battler).stats.max_hp < ENEMY_COMBATANT(g_Battle.active_battler).hp) {
                    ENEMY_COMBATANT(g_Battle.active_battler).hp = ENEMY_COMBATANT(g_Battle.active_battler).stats.max_hp;
                }
            }
        }
    }
    if (!(u8)Battle_PickAbility(g_Battle.active_battler, g_Battle.target)) {
        if (g_Battle.target < 3) {
            member_chr = &g_Game.members[g_Battle.target].chr;
            value      = member_chr->hp;
        } else {
            value = ENEMY_COMBATANT(g_Battle.target).hp;
        }
        g_Battle.target_record->hp_change = value - 1;
    }
}
