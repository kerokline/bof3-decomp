#include "battle_15.h"

/* Sets the panel task's unk_08 byte to 2 and its y half to -10. */
MATCH void func_800A0C44(void) {
    *(s8*)(((s32)g_BattleTargetRecord + 8)) = 2;
    *(s16*)((s32)g_BattleTargetRecord + 6)  = -10;
}
