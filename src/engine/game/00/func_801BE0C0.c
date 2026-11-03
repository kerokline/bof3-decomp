#include "game_00.h"

MATCH s8 func_801BE0C0(s32 pos_x, s32 pos_y, s32 range_mode) {
    /* FAKE: call-result and loop-copy registers, as the matched BDE14 slot scan. */
    MATCH_REG(s16, v, "s4");
    MATCH_REG(s32, a1v, "a1");
    MATCH_REG(s32, a0v, "a0");
    /* FAKE: loop bound in the retail register. */
    MATCH_REG(s32, limit, "v0");
    /* FAKE: unused frame, 8 bytes. */
    STACK_PADS(u8, 8);
    s32 count;
    s32 idx;
    s32 off;
    u8* ptr;

    v     = func_801BDCF8();
    idx   = 0;
    count = g_PartySize;
    if (count > 0) {
        off = 0;
        do {
            ptr = (u8*)g_BattlePartyBattlers + off;
            if (((void*)ptr != (void*)g_SpadWork) && (((u8*)g_BattlePartyBattlers)[off] != 0)) {
                a1v = pos_y;
                a0v = pos_x;
                if ((func_801BDD58(a0v, a1v, v, range_mode, (Actor*)ptr) & BYTE_MASK) != 0) {
                    return (s8)idx;
                }
            }
            limit = g_PartySize;
            idx += 1;
            off += BATTLE_PARTY_STRIDE;
        } while (idx < limit);
    }
    return -1;
}
