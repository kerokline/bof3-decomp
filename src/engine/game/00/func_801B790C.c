#include "game_00.h"

MATCH void func_801B790C(void) {
    u8*      work    = SP_REF(u8*, 0x44);
    Callback handler = D_801CD310[work[4]];
    handler();
}
