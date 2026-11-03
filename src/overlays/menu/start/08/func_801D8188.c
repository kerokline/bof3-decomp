#include "start_08.h"

MATCH void func_801D8188(void) {
    u8* slot = &D_80148624;
    /* FAKE: branch-select byte pinned to s0; gcc swaps s0/s1 without it (94.78%). */
    MATCH_FAKE_PIN(s8*, toggle, "s0");
    u16* key;
    u8*  count;
    s16  bar;
    s32  sel;

    Menu_DrawClutStrip(D_80144953);
    /* FAKE: hides slot's constant so the bar read stays s1-relative; pure form 87.93%. */
    MATCH_FAKE_OPAQUE(slot);
    bar        = *(u16*)(slot - 0x164);
    *slot      = 1;
    D_801484CC = 0x31;
    toggle     = &D_8014865B;
    sel        = 1 - *toggle;
    D_80148628 = bar + (sel << 5) + 0xDE;
    D_8014862A = D_801484C2 + 5;
    key        = &g_InputPressed;
    slot -= 0xB4;
    if (*key & (PADLright | PADLleft)) {
        SND_PlayCue(EMI_CUE_ID(1, 1));
        *toggle ^= 1;
    }
    if (*key & D_80145AC2) {
        if (*toggle != 0) {
            SND_PlayCue(EMI_CUE_ID(1, 4));
            Char_AddAbility(*(Party_GetAbilities(D_8014857A, D_8014857B, 0) + D_8014857C), 0, 1, 0);
            *(Party_GetAbilities(D_8014857A, D_8014857B, 0) + D_8014857C) = 0;
        } else {
            SND_PlayCue(EMI_CUE_ID(1, 6));
        }
        count = &D_80148651;
        *count -= 2;
        slot[0xD] = 0xFF;
        return;
    }
    if (*key & D_80145AC4) {
        D_8014857D = 0xFF;
        D_80148651 -= 2;
        SND_PlayCue(EMI_CUE_ID(1, 6));
    }
}
