#include "start_08.h"

/* Shop record state and draw helpers: D_801ED7F0 is the selected record index
 * (signed), D_801ED860 the overlay step counter. */

MATCH void func_801E5674(void) {
    s8 count;

    if (D_801ED7F0 == 4) {
        SND_PlayCue(EMI_CUE_ID(1, 2));
    }
    Menu_DrawClutStrip(D_80144953);
    Menu_DrawHeaderBar(0x14, 0x12, 0x118, 0x13, D_80144952);
    SAVE_DrawSlots(0x20 - D_801ED7F0 * 0x50, 0x30, 1);
    count      = (u8)D_801ED7F0 - 1;
    D_801ED7F0 = count;
    if (count == 0) {
        D_801ED860 += 1;
    }
}
