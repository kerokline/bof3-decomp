#include "boss013_16.h"

MATCH void func_800C1E90(void) {
    u8* flags;

    flags = &g_BattleBossFlags;
    if (*flags & 1) {
        g_BattleActionType = 3;
    } else if (D_800C26E0 != 0) {
        D_800C26E0--;
        g_BattleActionType = 0;
    } else {
        g_BattleActionType     = 1;
        g_BattleTargetSelector = 4;
        *flags |= 1;
        D_80146322--;
    }
}
