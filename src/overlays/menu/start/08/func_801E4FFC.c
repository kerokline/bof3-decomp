#include "start_08.h"

extern u8 D_801ED7FC; /* local: u8 read; a sibling copy is s8 */
extern u8 D_801ED800; /* local: u8 read; a sibling copy is s8 */

MATCH void func_801E4FFC(void) {
    Menu_DrawClutStrip(D_80144953);
    Menu_DrawHeaderBar(0x14, 0x12, 0x118, 0x13, D_80144952);
    D_801ED7F0 = 2;
    D_801ED7FC = 2;
    D_801ED800 = D_801ED860 + 1;
    D_801ED860 = 0xE;
}
