#include "shop_00.h"

MATCH void func_801D910C(u16 sprite_x, u16 sprite_y, u8 atlas_index, u8 shade_mode) {
    if (((atlas_index & BYTE_MASK) == 4) && (g_SceneState >= 8)) {
        atlas_index = 0xB;
    }
    Menu_DrawPortrait(sprite_x & HALF_MASK, sprite_y & HALF_MASK, atlas_index & BYTE_MASK, shade_mode & BYTE_MASK);
}
