#include "battle_15.h"

/* The target index selects one of three party members. */
#define BATTLE_ACTIVE_MEMBER_COUNT 3
/* Fatigue rises only below this value. */
#define BATTLE_TIMER_MAX           9

/* Raises the target member's fatigue below the cap, rebuilds its stats, then refreshes every member's equipment and
 * stat blocks and the formation bonuses before the target's max HP goes out as the HP change.
 */
MATCH void func_800A1D84(void) {
    Character* member_chr;
    s32        record_index;
    u8         i;
    Character* cell;
    u8         timer;

    if (g_Battle.target < BATTLE_ACTIVE_MEMBER_COUNT) {
        record_index = g_Game.members[g_Battle.target].character_index;
        timer        = g_Characters[record_index].fatigue;
        if (timer < BATTLE_TIMER_MAX) {
            g_Characters[record_index].fatigue = timer + 1;
            g_Game.members[g_Battle.target].chr.fatigue += 1;
        }
        Char_RebuildStats(&g_Characters[g_Game.members[g_Battle.target].character_index]);
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
        member_chr                        = &g_Game.members[g_Battle.target].chr;
        g_Battle.target_record->hp_change = -(s16)member_chr->stats.max_hp;
    }
}
