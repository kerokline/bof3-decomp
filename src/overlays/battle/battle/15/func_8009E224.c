#include "battle_15.h"

MATCH void func_8009E224(void) {
    *((u8*)(g_BattleTargetRecord) + 8)       = 2;
    (*(s16*)((u32)g_BattleTargetRecord + 6)) = -0x64;
}
