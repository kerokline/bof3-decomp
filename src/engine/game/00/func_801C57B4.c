#include "game_00.h"

MATCH void func_801C57B4(void) {
    g_SpadWork->x.fixed += g_SpadWork->unk_0C;
    g_SpadWork->y.fixed += g_SpadWork->unk_10;
    g_SpadWork->z.part.integer = (u16)(g_SpadWork->z.part.integer + g_SpadWork->vz);
}
