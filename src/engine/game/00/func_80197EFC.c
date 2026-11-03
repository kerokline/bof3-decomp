#include "game_00.h"

MATCH void func_80197EFC(void) {
    u16* state;

    func_801BF8E0();
    func_801BFAC4();
    func_801A06D8();
    func_801992B8();
    state = &g_GameEntrySubstate;
    (*state)++;
}
