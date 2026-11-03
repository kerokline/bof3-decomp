#include "shop_00.h"

MATCH void func_801D2D64(void) {
    s32 input;
    u8  previous;

    D_80148340 = 0x51;
    D_80148435 = 1;
    D_80148498 = 1;
    D_80148499 = 7;
    D_8014849A = 0xA;
    D_8014849C = (s16)D_80148430;
    D_8014849E = (D_80148432 + (D_801E6044 - D_80148437) * 0xD) + 0x14;
    D_801484A2 = D_801E6048;
    D_801484A3 = D_801E604C;
    D_801484A4 = D_801E6050;
    D_801484A5 = D_801E606C;
    input      = INPUT_REPEATED(g_InputPressed, INPUT_DIRECTIONAL);
    previous   = D_801E6050;
    if (input & PADLleft) {
        D_801E6050 -= 1;
    } else if (input & PADLright) {
        D_801E6050 += 1;
    }
    if ((s8)D_801E6050 <= 0) {
        D_801E6050 = 1;
    }
    if ((u8)D_801E605C < D_801E6050) {
        D_801E6050 = D_801E605C;
    }
    if (previous != D_801E6050) {
        SND_PlayCue(EMI_CUE_ID(1, 1));
    }
    if (input & PADLdown) {
        D_801E6050 -= 0xA;
    } else if (input & PADLup) {
        D_801E6050 += 0xA;
    }
    if ((s8)D_801E6050 <= 0) {
        D_801E6050 = 1;
    }
    if ((u8)D_801E605C < D_801E6050) {
        D_801E6050 = D_801E605C;
    }
    if (previous != D_801E6050) {
        SND_PlayCue(EMI_CUE_ID(1, 1));
    }
    if (g_InputPressed & D_80145AC2) {
        SND_PlayCue(EMI_CUE_ID(1, 3));
        D_8014865B = 1;
        D_80148652 += 1;
        return;
    }
    if (g_InputPressed & D_80145AC4) {
        SND_PlayCue(EMI_CUE_ID(1, 6));
        (*(s8*)&D_80148652)--;
    }
}
