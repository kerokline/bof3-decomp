#include "battle_03.h"

MATCH s32 func_801DD7D8(s32 low_bound, s32 high_bound, s32 current) {
    int low_below_current;

    low_below_current = low_bound < current;
    if (high_bound > current) {
        return low_bound;
    }
    if (low_below_current) {
        return high_bound;
    }
    return current;
}
