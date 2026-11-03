#include "game_00.h"

MATCH void func_801B76F4(void) {
    s16 dist;

    g_SpadWork->vz += g_SpadWork->gravity;
    func_801B0DFC();
    dist = Area_ReadHeight(g_SpadWork->x.fixed, g_SpadWork->y.fixed);
    if ((s16)g_SpadWork->z.part.integer < dist) {
        g_SpadWork->z.part.integer = dist;
        if (g_SpadWork->vz < -0x80) {
            Actor_RequestScript((g_SpadWork->direction_08 >> 1) + 0x34);
        } else if (g_SpadWork->direction_08 == 3) {
            Actor_RequestScript(0x38);
        } else {
            Actor_RequestScript(0x39);
        }
        g_SpadWork->vz      = 0;
        g_SpadWork->gravity = 0;
        g_SpadWork->unk_03  = 4;
    }
    if ((g_SpadWork->unk_05 == 0) &&
        (((g_GameFlags | g_AreaWalkFlags) & (GAME_FLAG_SCROLL_LOCK | AREA_WALK_ENTRY_ACTIVE)) == 0)) {
        Area_AdvanceScroll((s16)g_SpadWork->z.part.integer);
    }
    func_8014D978();
}
