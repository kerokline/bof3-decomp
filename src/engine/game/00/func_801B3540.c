#include "game_00.h"

MATCH void func_801B3540(void) {
    u8*      work    = SP_REF(u8*, 0x44);
    Callback handler = D_801CD154[work[3]];
    handler();
}
