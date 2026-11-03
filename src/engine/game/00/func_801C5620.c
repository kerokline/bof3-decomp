#include "game_00.h"

MATCH void func_801C5620(void) {
    u16 count;
    s32 x;
    s32 y;
    s16 result;

    x                          = g_SpadWork->x.fixed;
    count                      = g_SpadWork->z.part.integer;
    y                          = g_SpadWork->y.fixed;
    g_SpadWork->z.part.integer = count - 16;
    result                     = Area_ReadHeight(x, y);

    if ((s16)g_SpadWork->z.part.integer < result) {
        g_SpadWork->z.part.integer = (u16)result;
        Actor_SelectScript(g_SpadWork->direction_08);
        GFX_StagePalette(0x80035600u + g_SpadWork->unk_05 * 0x40u, 0);
        g_GameState->mode_12B.u8_value = 0;
        g_SpadWork->unk_01             = 1;
        ACTOR_CLEAR_STATE();
    }

    func_8014D978();
}
