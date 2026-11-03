#include "battle_15.h"

/* NOTE: byte-match requires the epilogue scheduler reorg: -fschedule-insns
 * hoists `lw ra` above the `sb` cell-store at g_BattleUiStep. A volatile access
 * pins the store in program order and blocks that hoist, so the increment is
 * issued through a plain (non-volatile) MEM view.
 */
MATCH void func_80096AB0(void) {
    BattleStageAttackNameMessage(0, 0);
    *(u8*)&g_BattleUiStep += 1;
}
