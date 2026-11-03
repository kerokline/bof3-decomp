#include "area191_13.h"

MATCH void func_801F2DBC(void) {
    u8* state;

    if (g_GameStateIndex != 2) {
        state              = &D_80146875;
        *state             = *state + 1;
        g_SpadWork->unk_01 = 3;
    }
    func_801F2E34();
}
