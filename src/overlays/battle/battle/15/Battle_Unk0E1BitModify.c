#include "battle_15.h"

/* func_8009C87C */
MATCH void Battle_Unk0E1BitModify(u8* record, s32 bit, u8 set) {
    u8 mask;

    mask = BIT(bit);
    if (set != 0) {
        record[0xE1] |= mask;
    } else {
        record[0xE1] &= ~mask;
    }
}
