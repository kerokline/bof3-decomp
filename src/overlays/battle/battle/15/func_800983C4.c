#include "battle_15.h"

MATCH void func_800983C4(void) {
    u32 temp = Resource_Resolve(0x4000);
    BattleStageSelectionRingRecord(2, 0xFF, temp);
    *(u8*)&g_BattleUiState += 1;
}
