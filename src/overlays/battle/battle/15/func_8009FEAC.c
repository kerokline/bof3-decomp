#include "battle_15.h"

/* Sets the panel task's unk_08 byte to 2 and its y half to -5. */
MATCH void func_8009FEAC(void) {
    *((u8*)(g_BattleTargetRecord) + 8)       = 2;
    (*(s16*)((u32)g_BattleTargetRecord + 6)) = -5;
}
