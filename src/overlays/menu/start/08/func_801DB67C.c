#include "start_08.h"

MATCH void func_801DB67C(void) {
    s32 off;
    u8  i;
    u8  value;
    s16 offset;

    Menu_DrawClutStrip(D_80144953);
    i      = 0;
    value  = 4;
    offset = -0x96;
    for (; i < Party_CountOrder(0); i++) {
        off                             = (i + 4) * 0x24;
        D_80148333[off]                 = value;
        *(s16*)((u8*)&D_80148334 + off) = offset;
    }
    D_8014842F = 2;
    D_80148453 = 2;
    D_80148477 = 2;
    D_8014849B = 2;
    D_80148654 = 0;
    D_80148650 = 1;
    D_80148651 = 0;
    D_80148652 = 0;
    D_80148655 = D_801ED6A0;
}
