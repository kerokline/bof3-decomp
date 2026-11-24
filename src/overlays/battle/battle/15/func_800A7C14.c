#include "battle_15.h"

/* Rebuilds the stat display template from a dragon-form row and applies it to the active member's live record. */
MATCH void func_800A7C14(u8 slot) {
    Character* battler;
    Character* character;
    u8         ability;
    u8         ability_id;
    u8         index;
    s16        max_hp;

    for (index = 0; index < g_Battle.party_count; index++) {
        s_BattleBattlerTemplates[index] = g_Game.members[index];
    }

    battler   = &g_Game.members[g_Battle.active_battler].chr;
    character = &g_Characters[g_Game.members[g_Battle.active_battler].character_index];

    D_801EBEF0.max_hp     = func_801DE0F8(character->base.max_hp, D_800B4EE0[slot][0] * 10);
    max_hp                = D_801EBEF0.max_hp - ((D_801EBEF0.max_hp * character->fatigue + 5) / 10);
    battler->base.max_hp  = max_hp;
    battler->stats.max_hp = max_hp;
    battler->hp           = max_hp;

    D_801EBEF0.power     = battler->base.power;
    battler->stats.power = battler->base.power = func_801DE0AC(battler->base.power, D_800B4EE0[slot][1] * 10);
    D_801EBEF0.power                           = battler->stats.power - D_801EBEF0.power;

    D_801EBEF0.defense     = battler->base.defense;
    battler->stats.defense = battler->base.defense = func_801DE0AC(battler->base.defense, D_800B4EE0[slot][2] * 10);
    D_801EBEF0.defense                             = battler->stats.defense - D_801EBEF0.defense;

    D_801EBEF0.agility     = battler->base.agility;
    battler->stats.agility = battler->base.agility = func_801DE0AC(battler->base.agility, D_800B4EE0[slot][3] * 10);
    D_801EBEF0.agility                             = battler->stats.agility - D_801EBEF0.agility;

    D_801EBEF0.intelligence     = battler->base.intelligence;
    battler->stats.intelligence = battler->base.intelligence = func_801DE0AC(battler->base.intelligence, D_800B4EE0[slot][4] * 10);
    D_801EBEF0.intelligence                                  = battler->stats.intelligence - D_801EBEF0.intelligence;

    D_801EBEF0.resistances[0] = battler->stats.resistances[0] = battler->base.resistances[0] = D_800B4EE0[slot][5];
    D_801EBEF0.resistances[1] = battler->stats.resistances[1] = battler->base.resistances[1] = D_800B4EE0[slot][6];
    D_801EBEF0.resistances[2] = battler->stats.resistances[2] = battler->base.resistances[2] = D_800B4EE0[slot][7];
    D_801EBEF0.resistances[3] = battler->stats.resistances[3] = battler->base.resistances[3] = D_800B4EE0[slot][8];
    D_801EBEF0.resistances[4] = battler->stats.resistances[4] = battler->base.resistances[4] = D_800B4EE0[slot][9];
    D_801EBEF0.resistances[5] = battler->stats.resistances[5] = battler->base.resistances[5] = D_800B4EE0[slot][10];
    D_801EBEF0.resistances[6] = battler->stats.resistances[6] = battler->base.resistances[6] = D_800B4EE0[slot][11];
    D_801EBEF0.resistances[7] = battler->stats.resistances[7] = battler->base.resistances[7] = D_800B4EE0[slot][12];
    D_801EBEF0.resistances[8] = battler->stats.resistances[8] = battler->base.resistances[8] = D_800B4EE0[slot][13];

    for (index = 0, ability = 0; index < 8; index++, ability++) {
        if (ability == CHARACTER_ABILITY_COUNT - 1) {
            break;
        }
        ability_id = D_800B5008[slot][index];
        if (ability_id == 0) {
            break;
        }
        battler->abilities.attack[ability] = ability_id;
    }
    battler->abilities.attack[ability] = 0xD9;
    for (ability++; ability < CHARACTER_ABILITY_COUNT; ability++) {
        battler->abilities.attack[ability] = 0;
    }
}
