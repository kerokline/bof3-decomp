#include "area106_13.h"

MATCH void func_801F2C8C(void) {
    void* state;

    state           = SP_REF(void*, 0x44);
    g_AreaSceneMode = 2;
    FIELD(u8, state, 0x2u)++;
}
