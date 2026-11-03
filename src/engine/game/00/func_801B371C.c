#include "game_00.h"

MATCH void func_801B371C(void) {
    u8*      work    = SP_REF(u8*, 0x44);
    Callback handler = D_801CD1B0[work[2]];

    handler();
    func_8014D978();
}
