#include "area008_13.h"

MATCH void func_801F43C8(void) {
    sprintf(g_TextVariables[0], D_801F2C14, WORLD00_AREA008_D_80146867 & 0x7F);
    Message_StartAreaMessage(0x56);
    g_GameStateIndex = 2;
    SND_PlayBgm(0xA, 0x64, 8);
}
