#include "area077_14.h"

MATCH void func_801F3198(u8 blend_mode) {
    GFX_SET_DRAW_MODE(GetTPage(0, blend_mode, 960, 0));
    GFX_AddPrim(1, 0xC);
}
