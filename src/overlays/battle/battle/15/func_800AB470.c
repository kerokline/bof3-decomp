#include "battle_15.h"

MATCH s32 func_800AB470(u8 battler_index) {
    u16 value;

    value = D_80145FAA[battler_index * 160];
    if (value == 0x4C)
        return 1;
    if (value == 0x4D)
        return 1;
    if (value != 0xB4)
        return value == 0xB5;
    return 1;
}
