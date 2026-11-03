#include "boss008_16.h"

MATCH void func_800C1AB4(void) {
    u8* work;
    u8* spad;

    func_800C236C(g_SpadWork[9]);
    work = g_SpadWork;
    if (work[9] == 0x30) {
        work[0x48]             = 2;
        spad                   = g_SpadWork;
        FIELD(u32, spad, 0x40) = 0x10000;
        FIELD(u32, spad, 0x44) = 0x10000;
        SND_PlayCue(EMI_CUE_ID(6, 2));
        g_SpadWork[4]++;
    } else {
        work[9] += 4;
    }
}
