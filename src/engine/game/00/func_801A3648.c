#include "game_00.h"

/* Signed byte view of the three palette-offset counters inside each
 * 12-byte PaletteFade, at the D_80145BD6 label. */

MATCH void func_801A3648(void) {
    u8 index;

    index = g_CurrentActor->unk_93;
    if (D_80145BD6[index].red_offset != 0) {
        D_80145BD6[index].red_offset -= 1;
    }
    index = g_CurrentActor->unk_93;
    if (D_80145BD6[index].green_offset != 0) {
        D_80145BD6[index].green_offset -= 1;
    }
    index = g_CurrentActor->unk_93;
    if (D_80145BD6[index].blue_offset != 0) {
        D_80145BD6[index].blue_offset -= 1;
    }
    index = g_CurrentActor->unk_93;
    if ((D_80145BD6[index].blue_offset + D_80145BD6[index].green_offset + D_80145BD6[index].red_offset) == 0) {
        GFX_FreePaletteFade(index);
        ((Actor*)g_CurrentActor)->flags_74 &= ~ACTOR_FLAG_FADE_WHITE;
        g_SpadWork->unk_01 = g_SpadWork->unk_03;
        g_SpadWork->unk_04 = 0;
    }
}
