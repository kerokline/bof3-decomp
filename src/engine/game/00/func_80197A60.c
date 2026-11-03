#include "game_00.h"

MATCH void func_80197A60(void) {
    u16* state;

    func_801BEDD0();
    func_801A06D8();
    func_801992B8();
    state = &g_GameEntrySubstate;
    (*state)++;
}
