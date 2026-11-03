#include "area040_13.h"

MATCH void func_801F2C74(void) {
    void* temp_v0_21;

    if (g_GameState->slot_index_79 == 2) {
        temp_v0_21                    = SP_REF(void*, 0x44);
        FIELD(s32, temp_v0_21, 0x34u) = (s32)(FIELD(s32, temp_v0_21, 0x34u) + 0x8000);
    }
}
