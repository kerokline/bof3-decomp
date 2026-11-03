#include "area008_13.h"

MATCH void func_801F2E1C(void) {
    volatile Actor* previous;
    u8              tmp;

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
    tmp        = (u8)(D_801F53F4 - 1);
    D_801F53F4 = tmp;
    if ((tmp & BYTE_MASK) < 2) {
        D_80146866                = 2;
        previous                  = g_SpadWork;
        WORLD00_AREA008_STATE_PTR = (volatile Actor*)&g_BattlePartyBattlers[1];
        g_SpadWork                = (u8*)&g_BattlePartyBattlers[1];
        Actor_SelectScript(1);
        D_801F53F4       = D_801F4680[RANDOM_MASK(3)];
        g_SpadWork       = previous;
        previous->unk_01 = 4;
    }
}
