#include "game_00.h"

MATCH void func_801B2D90(void) {
    u8*      work    = SP_REF(u8*, 0x44);
    Callback handler = D_801CD120[work[2]];

    handler();
    func_8014D978();
}
