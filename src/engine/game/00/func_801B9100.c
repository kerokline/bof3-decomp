#include "game_00.h"

MATCH void func_801B9100(void) {
    Actor* work;
    s32    adjustment;
    s16    distance;

    work               = g_SpadWork;
    work->direction_08 = (work->direction_08 + 1) & 7;
    adjustment         = work->vz - 8;
    work->z.part.integer += adjustment;
    work->vz = adjustment;
    Actor_RequestScript(g_SpadWork->direction_08);
    distance = Area_ReadHeight(g_SpadWork->x.fixed, g_SpadWork->y.fixed);
    if (distance - (s16)g_SpadWork->z.part.integer >= 0x101) {
        u8* state = &g_GameStateIndex;

        if (*state != GAME_REQUEST_AREA_CHANGE) {
            *state = GAME_REQUEST_AREA_CHANGE;
            g_AreaWalkFlags |= 0x200;
        }
    }
}
