#include "area105_13.h"

MATCH void func_801F2C48(void) {
    /* FAKE: retail reads D_80146874 as u16. */
    if ((*(u16*)&D_80146874) == 0x20C) {
        SND_PlayCue(EMI_CUE_ID(2, 2));
        FIELD(u8, g_SpadWork, 0x2u)++;
    }
}
