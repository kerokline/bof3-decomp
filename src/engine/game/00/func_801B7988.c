#include "game_00.h"

MATCH void func_801B7988(void) {
    u16 next;

    next = g_SpadWork->z.part.integer;
    next += 0x10;
    g_SpadWork->z.part.integer = next;
    if ((s16)next > Area_ReadHeight(g_SpadWork->x.fixed, g_SpadWork->y.fixed) + 0x200)
        g_GameStateIndex = 5;
    func_8014D978();
}
