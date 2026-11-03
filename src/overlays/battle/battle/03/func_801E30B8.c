#include "battle_03.h"

MATCH u8 func_801E30B8(u8 slot_offset) {
    if (BATTLE_GLOBAL_BYTE_62F3 != 1u) {
        return Battle_PickRandomTarget((u8)(slot_offset + 3));
    }

    return 0xFF;
}
