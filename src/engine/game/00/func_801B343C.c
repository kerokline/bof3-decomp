#include "game_00.h"

MATCH void func_801B343C(void) {
    if (func_801C4FE0() & BYTE_MASK) {
        g_SpadWork->state_02 = 2;
        g_SpadWork->unk_03   = 0;
    }
}
