#include "area030_04.h"

/* Counts down the AREA030 scratch timer at +0x2E; on expiry it
 * resets the timer and the state byte, otherwise it runs the shared
 * state dispatcher. */
MATCH void func_801D3574(void) {
    u8* record;
    s32 val;

    record                    = (u8*)g_SpadWork;
    val                       = *(u16*)((record + 0x2Eu)) - 0x1E;
    *(u16*)((record + 0x2Eu)) = (u16)val;

    if ((s16)val < -0x45) {
        *(u16*)((record + 0x2Eu)) = 0xA0;
        record[1]                 = 0;
        return;
    }

    Area_AddActor();
}
