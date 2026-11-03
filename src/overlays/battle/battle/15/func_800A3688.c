#include "battle_15.h"

MATCH s32 func_800A3688(s32 battler_index, s32 compare_value) {
    return BattleCompareStatusByte(battler_index, compare_value, 0x85);
}
