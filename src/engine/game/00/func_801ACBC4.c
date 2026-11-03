#include "game_00.h"

MATCH void func_801ACBC4(void) {
    u8*      work    = SP_REF(u8*, 0x44);
    Callback handler = D_801C8904[work[4]];
    handler();
}
