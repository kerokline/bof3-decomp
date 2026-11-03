#include "battle_15.h"

/* Non-volatile view of the active battler index (0x80146394): battle_15.h
 * declares it volatile, whose byte load cannot feed the index arithmetic
 * without an extra mask. */

/* sets the battler-dirty flag, then marks the active battler's
 * damage-status row present and clears its pending-select bit: player rows
 * below index 3, enemy rows above.
 */
MATCH void func_800A3F28(void) {
    u32           battler_index;
    volatile u16* pFlag;
    u16           flag;

    pFlag         = &g_BattleState;
    flag          = *pFlag;
    battler_index = g_BattleTarget_nv;
    *pFlag        = flag | BATTLE_STATE_DAMAGE_APPLIED;
    if (BATTLER_IS_PLAYER(battler_index)) {
        g_BattlePartyBattlers[battler_index].flags_124.volatile_value |= COMBATANT_FLAG_DAMAGE_ROW_PRESENT;
        g_BattlePartyBattlers[g_BattleTarget].unk_120 &= ~0x1u;
    } else {
        D_801EB730[battler_index - 3u].flags_00 |= COMBATANT_FLAG_DAMAGE_ROW_PRESENT;
        D_801EB72C_rows[g_BattleTarget - 3u].flag &= ~0x1u;
    }
}
