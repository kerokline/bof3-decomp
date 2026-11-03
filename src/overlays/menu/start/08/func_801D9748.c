#include "shared/etc.h"

extern u8  D_801484BD;
extern u8  D_801484BE;
extern u8  D_801484BF;
extern s16 D_801484C0;
extern s16 D_801484C2;
extern s16 D_801484CC;
extern u8  D_801485B8;
extern u8  D_801485B9;
extern u8  D_801485BA;
extern s16 D_801485BC;
extern s16 D_801485BE;
extern u8  D_80148654;
extern u8  D_801ED68C;

/* nonmatching unmeasured: tried the first draft cleaned to compiling C; best score 92.47%. resume: a lever or header fix that
 * closes the first mismatch. */
#ifdef NON_MATCHING
NON_MATCHING void func_801D9748(void) {
    volatile u8*   record;
    MenuPanelTask* rows;
    u8             i;

    record     = &D_801484BC;
    i          = 0;
    rows       = (MenuPanelTask*)(record + 0x120);
    D_801484BD = 6;
    D_801484BE = 9;
    D_801484BF = 2;
    record[0]  = 1;
    D_801484C0 = 0x14;
    D_801484C2 = -0x14;
    D_801484CC = 0;
    while (i < 2) {
        rows[i].unk_00[1] = 6;
        rows[i].unk_00[2] = 0xA;
        rows[i].unk_00[0] = 0;
        rows[i].unk_0A    = 0;
        i++;
    }
    D_801485BA        = 0xD;
    g_BattlePanelMode = 2;
    D_801485B8        = 1;
    g_BattleItemRow   = 7;
    D_801485C3        = 0xFF;
    D_801485BC        = 0x70;
    D_801485BE        = -0x14;
    D_801485B9        = 6;
    D_80148625        = 6;
    D_80148626        = 0xE;
    D_80148624        = 0;
    Menu_DrawClutStrip(D_80144953);
    D_801ED68C = 0;
    SND_PlayCue(EMI_CUE_ID(1, 2));
    D_80148654 = 5;
    D_80148652 = 0;
    D_80148651 += 1;
}
#else
INCLUDE_ASM(func_801D9748);
#endif
