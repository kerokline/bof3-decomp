#include "start_08.h"

extern s8 D_80148656;

/* nonmatching unmeasured: tried the first draft cleaned to compiling C; best score 68.31%. resume: a lever or header fix that
 * closes the first mismatch. */
#ifdef NON_MATCHING
NON_MATCHING void func_801D8680(void) {
    s16* val0;
    s32  tmp0;
    s32  val1;
    u8   tmp1;
    u8   tmp2;
    u8   tmp3;

    Menu_DrawClutStrip(D_80144953);
    *(s16*)(&D_801484CC) = 0x18;
    D_80148624           = 1;
    val0                 = &D_801484CC + 0xEC;
    D_801485C4           = 0xFF;
    D_8014857C           = 0xFF;
    D_80148628           = D_801485BC + 5;
    D_8014862A           = D_801485BE + ((D_801485C3 * 0x10) + 0x1A);
    tmp0                 = INPUT_GetRepeatedButtons(g_InputPressed & (PADLup | PADLdown));
    val1                 = D_8014857B == 3;
    if (tmp0 & PADLup) {
        SND_PlayCue(EMI_CUE_ID(1, 0));
        tmp3       = D_801485C3 - 1;
        D_801485C3 = tmp3;
        if (tmp3 & 0x80) {
            D_801485C3 = *(&D_801EC4A4 + ((val1 & BYTE_MASK) * 6)) - 1;
        }
    } else if (tmp0 & PADLdown) {
        SND_PlayCue(EMI_CUE_ID(1, 0));
        tmp2       = D_801485C3 + 1;
        D_801485C3 = tmp2;
        if ((*(&D_801EC4A4 + ((val1 & BYTE_MASK) * 6)) - 1) < (tmp2 & BYTE_MASK)) {
            D_801485C3 = 0;
        }
    }
    if (D_80145AC2 & g_InputPressed) {
        SND_PlayCue(EMI_CUE_ID(1, 3));
        tmp1 = FIELD(u8, (((val1 & BYTE_MASK) * 6) + &D_801EC4A4 + FIELD(u8, (val0), 0xB)), 0x1u);
        if (tmp1 != 0) {
            func_801D9304((s32)tmp1);
            return;
        }
        D_8014857D = 0xFF;
        D_80148652 += 1;
        D_8014857C = s_SkillOrderCursors[D_80148656][D_8014857B];
        return;
    }
    if (D_80145AC4 & g_InputPressed) {
        SND_PlayCue(EMI_CUE_ID(1, 6));
        FIELD(s8, (&D_801484CC), 0xECu) = 0;
        D_80148652 -= 1;
    }
}
#else
INCLUDE_ASM(func_801D8680);
#endif
