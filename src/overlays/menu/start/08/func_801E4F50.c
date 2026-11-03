#include "start_08.h"

MATCH void func_801E4F50(void) {
    Menu_DrawClutStrip(D_80144953);
    Menu_DrawHeaderBar(0x14, (D_801ED7F0 * 20 + 0x12) & 0xFFFE, 0x118, 0x13, D_80144952);
    if (D_801ED7F0 > 0) {
        D_801ED7F0--;
    }
    if (WINDOW_EFFECT_IDLE()) {
        D_801ED860++;
    }
}
