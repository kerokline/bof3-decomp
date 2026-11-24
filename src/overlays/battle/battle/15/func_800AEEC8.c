#include "battle_15.h"

/* Queues a 0x48 effect for the current task: mode arg0, or 8 when the target check fails. */
MATCH void func_800AEEC8(s32 arg0, u8 arg1) {
    u8 mode;
    u8 selector;
    u8 slot;
    mode = arg0;
    slot = arg1;
    if (g_Battle.target_selector & BATTLE_TARGET_ENEMY_SIDE) {
        selector = D_800B6BF0[arg0 & 3];
        slot     = arg1 + 3;
    } else {
        selector = D_800B6BF0[arg0 & 3];
    }
    if ((u8)Battle_CanTarget(selector, slot) == 0) {
        mode = 8;
    }
    slot                               = Battle_AllocEffect(1, 0x48);
    g_BattleEffects[slot].target.party = g_Task;
    g_BattleEffects[slot].unk_04       = mode;
    g_BattleEffects[slot].arg.unk_09   = 1;
    g_BattleEffects[slot].unk_0A       = 0;
}
