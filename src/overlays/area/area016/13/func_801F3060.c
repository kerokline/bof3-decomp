#include "area016_13.h"

/* Each access reloads the work cell: the stores go through its pointer, which
 * the compiler must assume may alias the cell. */

MATCH void func_801F3060(void) {
    ((u8*)g_SpadWork)[0x24] = 0x80;
    Area_FindSceneRecord(0xF);
    ((u8*)g_SpadWork)[0x29] = 5;
    ((u8*)g_SpadWork)[0x2A] = 0;
    ((u8*)g_SpadWork)[0x5D] = 0;
    ((u8*)g_SpadWork)[0x5E] = 0;
    ((u8*)g_SpadWork)[0x5F] = 0;
    ((u8*)g_SpadWork)[0x01] = 1;
}
