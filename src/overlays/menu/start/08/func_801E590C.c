#include "start_08.h"

extern s8 D_801ED7FC; /* local: s8 read; a sibling copy is u8 */
extern s8 D_801ED800; /* local: s8 read; a sibling copy is u8 */

MATCH void func_801E590C(void) {
    u8 count;

    Menu_DrawClutStrip(D_80144953);
    Menu_DrawHeaderBar(0x14, 0x12, 0x118, 0x13, D_80144952);
    WinDrawCueText(28, 21, 0xB9);
    SAVE_DrawSlots(0x20, 0x30, 0);
    if ((Menu_ToggleOption() & BYTE_MASK) != 0) {
        if (D_8014865B != 0) {
            count      = D_801ED860;
            D_801ED7FC = 0xA;
            D_801ED860 = 0xE;
            D_801ED7F0 = 2;
            D_801ED800 = count + 1;
            return;
        }
        D_801ED860--;
    }
}
