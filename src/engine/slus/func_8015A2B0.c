#include "engine/slus/slus.h"

/* draws one flat-coloured line into the current primitive: sets the
 * rgb byte, writes both corner points, then appends the 0x10-byte primitive to
 * ordering table 1.
 */
MATCH void func_8015A2B0(s16 start_x, s16 start_y, s16 end_x, s16 end_y, u8 gray) {
    u8* primitive;
    u8  color;
    s16 x0;
    s16 y0;
    s16 x1;
    s16 y1;

    primitive = g_GfxPrimCursor;
    color     = gray;
    x0        = start_x;
    y0        = start_y;
    x1        = end_x;
    y1        = end_y;
    SetLineF2((LINE_F2*)primitive);
    *(u8*)(primitive + 4)   = color;
    *(u8*)(primitive + 5)   = color;
    *(u8*)(primitive + 6)   = color;
    *(s16*)(primitive + 8)  = x0;
    *(s16*)(primitive + 10) = y0;
    *(s16*)(primitive + 12) = x1;
    *(s16*)(primitive + 14) = y1;
    GFX_AddPrim(1u, 0x10u);
}
