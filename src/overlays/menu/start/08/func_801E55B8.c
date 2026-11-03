#include "start_08.h"

/* Shop record draw helpers: D_801ED7F0 is the selected record index (signed),
 * D_801ED860 the overlay step counter. */

MATCH void func_801E55B8(void) {
    s8 count;

    Menu_DrawClutStrip(D_80144953);
    Menu_DrawHeaderBar(0x14, 0x12, 0x118, 0x13, D_80144952);
    func_801E14A8(0x62 + D_801ED7F0 * 0x30, 0x4C, D_801ED870, LOBU(g_SaveCardPort), 0);
    count      = (u8)D_801ED7F0 + 1;
    D_801ED7F0 = count;
    if (count == 4) {
        D_801ED860 += 1;
    }
}
