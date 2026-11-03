#include "battle_03.h"

/* writes the shared sprite value into the selected 0xC-byte stance
 * record, then restarts the stance when the enemy re-selected it and the step
 * byte is set.
 */
MATCH void func_801DF7EC(void) {
    s32               offset;
    BattleSpriteSlot* entry;
    u8                sprite;
    u8                value;

    offset                            = g_SpadWork->unk_07 * 0xC;
    entry                             = (BattleSpriteSlot*)((u8*)D_80145BD4 + offset);
    sprite                            = D_80146308;
    entry->unk_04                     = sprite;
    entry->unk_03                     = sprite;
    *(u8*)((u8*)&D_80145BD6 + offset) = sprite;
    if ((g_BattleSelectionLatch == 0) ||
        (((value = D_801EB4D8[0]) != g_SpadWork->slot) && ((value & BATTLE_TARGET_PARTY_SIDE) == 0))) {
        GFX_FreePaletteFade(g_SpadWork->unk_07);
        g_SpadWork->unk_02 = 0;
    }
}
