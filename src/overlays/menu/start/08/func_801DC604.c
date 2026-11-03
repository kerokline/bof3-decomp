#include "start_08.h"

void Menu_DrawPortrait(u16 sprite_x, u16 sprite_y, u8 atlas_index, u8 shade_mode);

MATCH void func_801DC604(u16 sprite_x, u16 sprite_y, u8 atlas_index, u8 shade_mode) {
    if ((atlas_index == 4) && (g_SceneState.scenario_id >= 8)) {
        atlas_index = 0xB;
    }
    Menu_DrawPortrait(sprite_x, sprite_y, atlas_index, shade_mode);
}
