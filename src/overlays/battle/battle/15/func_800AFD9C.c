#include "battle_15.h"

/* Averages the x, y and vertical span of the living battlers (the enemies in
 * the 0x40 mode, otherwise the three party slots) into the camera work
 * record. */
MATCH void func_800AFD9C(void) {
    s32           i;
    s32           count;
    s32           sum_x;
    s32           sum_y;
    s32           sum_span;
    u8            flags;
    PartyBattler* work;

    count    = 0;
    sum_span = 0;
    sum_y    = 0;
    sum_x    = 0;
    flags    = g_BattleTargetSelector;
    if ((flags & 0xC0) != 0xC0) {
        if (flags & 0x40) {
            for (i = 0; i < 8; i++) {
                if (Battle_SlotIsBlocked((i + 3) & BYTE_MASK) == 0) {
                    count++;
                    sum_x += D_801EB630[i].coord_x_34 >> 9;
                    sum_y += D_801EB630[i].coord_y_38 >> 9;
                    sum_span += D_801EB630[i].word_3C.half.span_3E;
                }
            }
        } else {
            for (i = 0; i < BATTLE_PARTY_SLOT_COUNT; i++) {
                if (Battle_SlotIsBlocked(i & BYTE_MASK) == 0) {
                    count++;
                    sum_x += g_BattlePartyBattlers[i].coord_x_34.raw >> 9;
                    sum_y += g_BattlePartyBattlers[i].coord_y_38.raw >> 9;
                    sum_span += g_BattlePartyBattlers[i].word_3C.half.span_3E;
                }
            }
        }
        work                       = BATTLE_WORK;
        work->coord_x_34.raw       = (sum_x / count) << 9;
        work->coord_y_38.raw       = (sum_y / count) << 9;
        work->word_3C.half.span_3E = sum_span / count;
    }
}
