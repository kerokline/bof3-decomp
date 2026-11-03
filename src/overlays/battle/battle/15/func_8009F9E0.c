#include "battle_15.h"

MATCH void func_8009F9E0(void) {
    s16* ptr;

    ((u8*)(g_BattleTargetRecord))[8] |= 2;
    ((s16*)(g_BattleTargetRecord))[2] = -5;
    ptr                               = (s16*)g_BattleTargetRecord;
    ptr[3]                            = -1;
}
