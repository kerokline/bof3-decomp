#include "battle_15.h"

/* Sprite and palette blocks for the two panel slots. Not declared by headers;
 * the addresses are the binary's own. */

MATCH void func_800B4220(s16 x, s16 y, u8 selected) {
    s16 slot_x;
    u8* style;

    style = &D_80144952;
    UI_DrawWindow((s32)(u16)x, (s32)(u16)y, 45u, 20u, 0u, *style);
    UI_DrawText((s16)(x + 12), (s16)(y + 3), selected != GAME_NONE && selected != 0 ? 7 : 0, 0x10u,
                (u8*)&s_BattlePanelUseLabel);
    UI_DrawSpriteRun(x, y, selected == 0 ? &s_BattlePanelUnselectedMarker : &s_BattlePanelSelectedMarker, 1u);

    slot_x = (s16)(x + 0x30);
    UI_DrawWindow((s32)(u16)slot_x, (s32)(u16)y, 45u, 20u, 0u, *style);
    UI_DrawText((s16)(x + 55), (s16)(y + 3), selected != GAME_NONE && selected != 1 ? 7 : 0, 0x10u,
                (u8*)&s_BattlePanelEquipLabel);
    UI_DrawSpriteRun(slot_x, y, selected == 1 ? &s_BattlePanelUnselectedMarker : &s_BattlePanelSelectedMarker, 1u);
}
