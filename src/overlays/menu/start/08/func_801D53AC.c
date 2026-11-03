#include "start_08.h"

/* nonmatching 76.74%: retail reads D_801ED620 signed at 0x47D4 (lb) and
 * unsigned later, but the union view keeps the cell's address in s0 and falls
 * to 55.81%. resume: a form that reads it once as signed without materialising
 * the address. */
#ifdef NON_MATCHING
NON_MATCHING void func_801D53AC(void) {
    s32 pressed;
    u8  old;

    Menu_DrawClutStrip(D_80144953);
    D_80148624 = 1;
    D_8014862A = (u16)D_801484E6 + 4;
    D_80148511 = 1;
    D_80148628 = (u16)D_801484E4 + (s8)D_801ED620 * 0x30;
    D_801484EB = 0xFF;
    D_801484CC = D_801EC440[(s8)D_801ED620];
    pressed    = INPUT_GetRepeatedButtons(g_InputPressed & (PADLright | PADLleft));
    old        = D_801ED620;
    if (pressed & PADLleft) {
        D_801ED620 = old - 1;
        if ((s8)(old - 1) < 0) {
            D_801ED620 = 3;
        }
    }
    if (pressed & PADLright) {
        D_801ED620 += 1;
        if ((s8)D_801ED620 >= 4) {
            D_801ED620 = 0;
        }
    }
    if ((s8)old != (s8)D_801ED620) {
        SND_PlayCue(EMI_CUE_ID(1, 1));
    }
    if (g_InputPressed & D_80145AC2) {
        u8* step;

        SND_PlayCue(EMI_CUE_ID(1, 4));
        step       = &D_80148651;
        D_80148624 = 0;
        D_801484EB = D_801ED620;
        *step += 1;
        return;
    }
    if (g_InputPressed & D_80145AC4) {
        u8* step;

        SND_PlayCue(EMI_CUE_ID(1, 2));
        SND_PlayCue(EMI_CUE_ID(1, 6));
        step       = &D_80148651;
        D_801484BF = 1;
        D_801484E3 = 1;
        D_80148507 = 1;
        D_801485DC = 0;
        D_80148624 = 0;
        D_80148654 = 0;
        *step += 5;
    }
}
#else
INCLUDE_ASM(func_801D53AC);
#endif
