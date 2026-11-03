#include "area107_13.h"

MATCH void func_801F2C48(void) {
    void* state;

    if (g_GameStateIndex == 3) {
        state                  = SP_REF(void*, 0x44u);
        FIELD(u8, state, 0x1u) = 1;
    }
}
