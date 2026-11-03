#include "boss008_16.h"

MATCH void func_800C196C(void) {
    g_SpadWork[9]   = 0x40;
    g_SpadWork[0xA] = 0x40;
    SND_PlayCue(EMI_CUE_ID(6, 1));
    g_SpadWork[4]++;
}
