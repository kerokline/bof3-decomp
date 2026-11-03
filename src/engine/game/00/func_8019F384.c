#include "game_00.h"

MATCH void func_8019F384(void) {
    s32 offset;

    g_SpadWork->unk_09 -= 1;
    offset = g_SpadWork->unk_0B * BATTLE_PARTY_STRIDE;
    func_8019F5B8(*(s16*)(((u8*)&g_BattlePartyBattlers[0].unk_2E) + offset),
                  (s16)(*(u16*)(((u8*)&g_BattlePartyBattlers[0].unk_30) + offset) + (u16)g_SpadWork->y.part.integer),
                  g_SpadWork->unk_06, g_SpadWork->unk_27);
    if (g_SpadWork->unk_09 == 0) {
        g_SpadWork->unk_01 += 1;
    }
}
