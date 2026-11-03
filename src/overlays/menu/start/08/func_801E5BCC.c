#include "start_08.h"

MATCH void func_801E5BCC(void) {
    Menu_DrawClutStrip(D_80144953);
    Menu_DrawHeaderBar(0x14, 0x12, 0x118, 0x13, D_80144952);
    SAVE_DrawSlots((D_801ED7F0 * 0x50) + 0x20, 0x30, 0);
    D_801ED7F0 += 1;
    if (D_801ED7F0 == 4) {
        D_801ED860 = 2;
    }
}
