#include "area030_04.h"

/* Counts down the AREA030 scratch timer at +0x2E; when it falls
 * below the threshold it reloads the counter pair and advances the state
 * byte, then runs the shared state dispatcher. */
MATCH void func_801D34A0(void) {
    u8* record;
    s32 val;
    u8* state;

    record = (u8*)g_SpadWork;

    val                       = *(u16*)((record + 0x2Eu)) - 0x1E;
    *(u16*)((record + 0x2Eu)) = (u16)val;

    if ((s16)val < 0xA1) {
        record[9]                 = 0x1E;
        state                     = (u8*)g_SpadWork;
        *(u16*)((record + 0x2Eu)) = 0xA0;
        state[1]                  = (u8)(state[1] + 1);
    }

    Area_AddActor();
}
