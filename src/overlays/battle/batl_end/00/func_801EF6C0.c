#include "batl_end_00.h"

MATCH s32 func_801EF6C0(void) {
    u8 slot;

    for (slot = 0; slot < g_BattlePartyCount; slot++) {
        if (func_801DB524(slot) == 0) {
            if ((D_80145F16[slot][0] == 7) || (D_80145F17[slot][0] == 7)) {
                return 1;
            }
        }
    }

    return 0;
}
