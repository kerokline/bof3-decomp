#include "area008_13.h"

MATCH void func_801F2D24(void) {
    volatile Actor* previous;

    if ((WORLD00_AREA008_D_80146867 & 0x80u) != 0u) {
        g_SpadWork->unk_01 = 9;
        return;
    }
    if (D_80146865 == 1) {
        D_80146866         = 5;
        D_80146865         = 2;
        g_SpadWork->unk_01 = 6;
        return;
    }
    previous                  = g_SpadWork;
    WORLD00_AREA008_STATE_PTR = (volatile Actor*)&g_BattlePartyBattlers[1];
    g_SpadWork                = (u8*)&g_BattlePartyBattlers[1];
    if (D_80146028 == 4 && D_8014601A == 1) {
        D_801F53F4       = D_801F4674[RANDOM_MASK(7)];
        g_SpadWork       = previous;
        previous->unk_01 = 3;
    }
}
