#include "battle_15.h"

/* candidate: the volatile-drop cell read (same shape as func_800A0898 in this
 * target) lets the prologue addiu sink into the first branch delay slot; the
 * record pin keeps the record in a1. Local object inspection equals the retail
 * object instruction for instruction (23/23). */
MATCH void func_800A39B4(s16 delta, u8 battler_index) {
    s8* record;
    s8  value;
    s32 total;
    s8  result;

    /* FAKE: volatile-drop cell read. */
    record = *(s8**)&g_BattleTargetRecord + battler_index;
    value  = record[0x14];
    total  = value + delta;
    if (total >= 51) {
        result = 0x32;
    } else if (total < -25) {
        result = -0x19;
    } else {
        result = (s8)(delta + value);
    }
    /* FAKE: statement boundary keeps the retail register order and schedule. */
    ORDER_LOCK(record[0x14] = result);
}
