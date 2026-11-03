#include "start_08.h"

/* The header spells D_80148628 a plain s16; this unit keeps the volatile
 * qualifier because the two adjacent halfword stores then keep the retail's
 * order and its measured bytes (58.33% against 57.74% without it). */
extern volatile s16 D_80148628;

/* nonmatching unmeasured: tried the first draft cleaned to compiling C; best score 65.79%. resume: a lever or header fix that
 * closes the first mismatch. */
#ifdef NON_MATCHING
NON_MATCHING void func_801D7314(void) {
    s16 tmp0;
    s32 tmp1;
    s32 tmp2;
    s32 val0;
    s32 val1;
    u8  tmp3;
    u8  tmp4;
    u8  tmp5;

    Menu_DrawClutStrip(D_80144953);
    D_80148578 = 0;
    tmp1       = *(&D_801EC488 + ((s8)D_801ED648 * 4));
    D_80148624 = 1;
    tmp0       = (u16)D_801484E6 + 4;
    D_80148628 = (u16)D_801484E4 + ((s8)D_801ED648 * 0x30);
    D_8014862A = tmp0;
    D_801484EB = 0xFF;
    D_801484CC = (s16)tmp1;
    tmp2       = INPUT_GetRepeatedButtons(g_InputPressed & (PADLright | PADLleft));
    tmp3       = D_801ED648;
    tmp4       = tmp3 - 1;
    if (tmp2 & PADLleft) {
        D_801ED648 = tmp4;
        val0       = tmp2 & PADLright;
        if (tmp4 & 0x80) {
            D_801ED648 = 3;
            goto block_3; /* retail branch */
        }
    } else {
    block_3:
        val0 = tmp2 & PADLright;
    }
    val1 = tmp3 << 0x18;
    if (val0 != 0) {
        tmp5       = D_801ED648 + 1;
        D_801ED648 = tmp5;
        val1       = tmp3 << 0x18;
        if ((s8)tmp5 >= 4) {
            D_801ED648 = 0;
        }
    }
    if ((val1 >> 0x18) != (s8)D_801ED648) {
        SND_PlayCue(EMI_CUE_ID(1, 1));
    }
    if (D_80145AC2 & g_InputPressed) {
        D_801484EB = D_801ED648;
        SND_PlayCue(EMI_CUE_ID(1, 4));
        switch ((s8)D_801ED648) { /* irregular */
            case 1:
                D_80148652 = 0;
                D_80148651 += 5;
                return;
            case 3:
                g_BattleChoicePhase = 1;
                D_80148654          = 7;
                D_80148652          = 0;
                D_80148651 += 7;
                return;
            case 2:
                D_8014857B = 3;
                /* fallthrough */
            default:
                D_80148651 += 1;
                return;
        }
    } else if (D_80145AC4 & g_InputPressed) {
        SND_PlayCue(EMI_CUE_ID(1, 2));
        SND_PlayCue(EMI_CUE_ID(1, 6));
        D_801484BF          = 1;
        D_801484E3          = 1;
        g_BattleChoicePhase = 1;
        D_80148624          = 0;
        D_80148654          = 5;
        D_80148651 += 6;
    }
}
#else
INCLUDE_ASM(func_801D7314);
#endif
