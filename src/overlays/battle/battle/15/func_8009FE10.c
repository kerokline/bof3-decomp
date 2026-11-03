#include "battle_15.h"

MATCH void func_8009FE10(void) {
    func_800A31E0(g_BattleTarget, 0x40);
    ((u8*)g_BattleTargetRecord)[8] |= 2;
    ((s16*)g_BattleTargetRecord)[2] = -0x14;
    ((s16*)g_BattleTargetRecord)[3] = -4;
}
