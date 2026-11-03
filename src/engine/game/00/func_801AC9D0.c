#include "game_00.h"

MATCH void func_801AC9D0(void) {
    u8*      work    = SP_REF(u8*, 0x44);
    Callback handler = D_801C88FC[work[4]];
    handler();
}
