#include "battle_15.h"

MATCH s8 func_800A7648(s8 index) {
    index += 2;
    CLAMP_MIN(index, 0);
    if (index >= 5) {
        index = 4;
    }
    return D_800B4E8C[index];
}
