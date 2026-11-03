#include "battle_03.h"

MATCH s16 func_801DE0F8(s32 arg0, s32 arg1) {
    s32 value;

    value = (arg0 * arg1) / 100;
    if (value >= 10000) {
        value = 9999;
    }
    CLAMP_MIN(value, 0);
    return value;
}
