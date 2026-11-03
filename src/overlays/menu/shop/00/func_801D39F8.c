#include "shop_00.h"

MATCH void func_801D39F8(void) {
    u8 count;
    u8 selection;

    /* The state byte is read before the delay counter is stored: the original
     * schedule interleaves the two accesses in that order. */
    count      = D_80148651;
    D_80148654 = 4;
    D_80148651 = count + 1;
    D_801E60F0 = 0;
    D_80148652 = 0;
    if (g_GameRequestFlags == 0x40 || g_GameAreaId == 188 || g_GameAreaId == 133 || g_GameAreaId == 193) {
        selection  = D_8014865C;
        D_8014865C = -2;
        D_8014865F = selection;
    }
    if (D_8014865C == -2) {
        D_80148651 = 3;
        D_80148652 = 0;
    }
}
