#include "area053_13.h"

MATCH void func_801F2C04(void) {
    u8* record;

    record                    = (u8*)g_ScriptWorkRecord;
    g_MessageRequest          = 0xFFFF;
    FIELD(s32, record, 0x18U) = D_801F363C[D_801490C7 * 2];
    /* FAKE: retail reloads the selection byte after the 0x18 store; the
     * compiler keeps the first load without a barrier (pure-C best 0x48/0x58). */
    MATCH_FAKE_BARRIER();
    FIELD(s32, record, 0x1CU) = D_801F363D[D_801490C7 * 2];
}
