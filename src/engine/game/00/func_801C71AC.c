#include "game_00.h"

MATCH s32 func_801C71AC(s32 delta) {
    s32 v0;
    s32 v1;

    v0 = delta;
    v1 = v0 << 0x10;
    if (v1 > 0) {
        return 1;
    }
    return v1 >> 0x1F;
}
