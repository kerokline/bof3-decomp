#include "game_00.h"

MATCH void func_801B207C(void) {
    Actor* work;
    s32    limit;
    s32    awake; /* FAKE: constant local orders the loop-invariant hoist (owner-approved dummy). */
    u8     frames;
    u8     i;

    g_SpadWork->unk_09 += 1;
    g_SpadWork->direction_08 = (g_SpadWork->direction_08 + 1) & 7;
    Actor_SelectScript(g_SpadWork->direction_08);
    frames = g_SpadWork->unk_09;
    for (i = 1; i < g_PartySize; i++) {
        work       = (Actor*)((u8*)g_BattlePartyBattlers + i * BATTLE_PARTY_STRIDE);
        g_SpadWork = work;
        awake      = 3;
        limit      = -(frames << 5);
        if (work->unk_01 == awake && limit < (s8)work->tint.bytes.unk_5D) {
            work->tint.bytes.unk_5D       = limit;
            g_SpadWork->tint.bytes.unk_5E = g_SpadWork->tint.bytes.unk_5D;
            g_SpadWork->tint.bytes.unk_5F = g_SpadWork->tint.bytes.unk_5D;
        }
    }
    g_SpadWork = (Actor*)g_BattlePartyBattlers;
    if (D_80145E99 == 4) {
        ((PartyBattler*)g_BattlePartyBattlers)[0].unk_02 += 1;
    }
}
