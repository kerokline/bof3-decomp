#include "area008_13.h"

MATCH void func_801F2F78(void) {
    u8   tmp;
    u16* halfword;

    if ((WORLD00_AREA008_D_80146867 & 0x80u) != 0u) {
        g_SpadWork->unk_01 = 9;
        return;
    }
    halfword   = D_80146876;
    D_80146866 = 0;
    if (halfword[0] == GAME_NONE) {
        halfword[0] = 0;
        D_801F53F4  = 2;
    }
    tmp        = (u8)(D_801F53F4 - 1);
    D_801F53F4 = tmp;
    if (tmp < 2) {
        D_80146865         = 0;
        g_SpadWork->unk_01 = 1;
    }
}
