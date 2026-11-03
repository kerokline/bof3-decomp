#include "battle_03.h"

MATCH s16 func_801DE0AC(s32 factor_a, s32 factor_b) {
    s32 value;

    value = (factor_a * factor_b) / 100;
    if (value >= 1000) {
        value = 999;
    }
    CLAMP_MIN(value, 0);
    return value;
}
