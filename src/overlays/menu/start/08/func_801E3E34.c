#include "start_08.h"

MATCH void func_801E3E34(u16 line_index) {
    SetDrawMode((DR_MODE*)g_GfxPrimCursor, 0, 0, GetTPage(0, 1, 960, line_index), 0);
    GFX_AddPrim(1, 0xC);
}
