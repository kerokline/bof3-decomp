#include "game_00.h"

MATCH void func_8019E918(void) {
    u8*      work    = SP_REF(u8*, 0x44);
    Callback handler = D_801C81B8[work[2]];
    handler();
}
