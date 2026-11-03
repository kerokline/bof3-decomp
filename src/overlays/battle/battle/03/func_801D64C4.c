#include "battle_03.h"

MATCH u8 func_801D64C4(u8 battler_index) {
    u16 flags;

    if (BATTLER_IS_PLAYER(battler_index)) {
        if (g_BattleActionLock == 0u) {
            /* no countdown: defer to the availability helper */
            goto fallback;
        }
        flags = (u16)D_80145FB8[battler_index][0];
    } else {
        if (g_BattleActionLock == 0u) {
            /* no countdown: defer to the availability helper */
            goto fallback;
        }
        flags = (u16)D_801EB734[(u32)battler_index - 3u][0];
    }

    if ((flags & 0x10u) == 0u) {
        return 1u;
    }

fallback:
    return Battle_SlotIsBlocked((u8)battler_index) != 0u;
}
