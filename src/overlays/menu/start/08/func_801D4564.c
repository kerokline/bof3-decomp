#include "start_08.h"

/* nonmatching unmeasured: tried the first draft cleaned to compiling C; best score 82.15%. resume: a lever or header fix that
 * closes the first mismatch. */
#ifdef NON_MATCHING
NON_MATCHING void func_801D4564(void) {
    s32 tmp0;
    u32 tmp1;
    u32 tmp2;
    u8  val1;

    Menu_DrawClutStrip(D_80144953);
    D_801484CC = Item_GetDescription(D_8014850E, D_801C893C[D_8014850E][D_80148510]);
    D_80148624 = 1;
    D_80148628 = (u16)D_80148508 + 7;
    D_8014862A = (u16)D_8014850A + (((D_80148510 - D_8014850F) * 0xD) + 0x1A);
    tmp0       = INPUT_GetRepeatedButtons(g_InputPressed & (PADLup | PADLdown | PADL1 | PADR1));
    if (tmp0 & PADLup) {
        if (D_80148510 != 0) {
            D_80148510 -= 1;
        }
        if ((u8)D_80148510 < (u8)D_8014850F) {
            D_80148516 = 0xF0;
        }
    } else if (tmp0 & PADLdown) {
        if ((u8)D_80148510 < 0x1FU) {
            D_80148510 += 1;
        }
        if ((s32)D_80148510 >= (D_8014850F + 9)) {
            D_80148516 = 0x10;
        }
    } else if (tmp0 & 4) {
        tmp1 = D_8014850F & BYTE_MASK;
        if (tmp1 == 0) {
            D_80148510 = 0;
        } else if (tmp1 < 9U) {
            D_80148510 -= D_8014850F;
            D_8014850F = 0;
        } else {
            D_80148510 -= 9;
            val1 = D_8014850F - 9;
            goto block_22; /* retail branch */
        }
    } else if (tmp0 & 8) {
        tmp2 = D_8014850F & BYTE_MASK;
        if (tmp2 == 0x17) {
            D_80148510 = 0x1F;
        } else {
            if (tmp2 >= 0xFU) {
                D_80148510 = (D_80148510 + 0x17) - D_8014850F;
                val1       = 0x17;
            } else {
                D_80148510 += 9;
                val1 = D_8014850F + 9;
            }
        block_22:
            D_8014850F = val1;
        }
    }
    s_ChoiceMenuCursors[D_80148504.group] = D_80148504.group_cursor;
    s_ChoiceMenuValues[D_80148504.group]  = D_80148504.group_first;
    if (D_80148510 != D_80148504.group_cursor) {
        SND_PlayCue(EMI_CUE_ID(1, 0));
    }
    if ((D_80148504.confirm_gate == 0) && (D_80145AC4 & g_InputPressed)) {
        SND_PlayCue(EMI_CUE_ID(1, 6));
        D_80148504.group               = 0U;
        D_80148504.group_cursor        = 0xFFU;
        FIELD(s8, (&D_80148504), 0xDu) = 0xFF;
        D_80148651 -= 7;
        D_80148504.group_first = (u8)*s_ChoiceMenuValues;
    }
}
#else
INCLUDE_ASM(func_801D4564);
#endif
