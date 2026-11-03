#include "game_00.h"

MATCH void func_801B7FE0(void) {
    Actor* work;
    Actor* store;
    s16    value;
    u8     arg;

    work = g_SpadWork;
    work->z.part.integer -= 0x10;
    if ((s16)work->z.part.integer < Area_ReadHeight(work->x.fixed, work->y.fixed)) {
        value                 = Area_ReadHeight(g_SpadWork->x.fixed, g_SpadWork->y.fixed);
        store                 = g_SpadWork;
        store->unk_09         = 2;
        store->z.part.integer = value;
        g_SpadWork->unk_0A    = 0;
        Actor_RequestScript((g_SpadWork->direction_08 == 3) ? 7 : 1);
        g_SpadWork->unk_04 = 9;
    }
    func_8014D978();
}
