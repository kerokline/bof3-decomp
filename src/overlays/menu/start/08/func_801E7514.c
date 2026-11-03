#include "start_08.h"

/* Icon geometry: five u16 fields per icon, a 10-byte stride. The original
 * reads each field through its own symbol-relative lui/addu/lhu, so the five
 * symbol bindings stay separate; a single struct base would materialize one
 * register and change the addressing. */
#define START08_ICON_STRIDE 10u

MATCH void func_801E7514(s32 x, s32 y, s32 icon, s32 palette) {
    u8* primitive;
    u32 geom;

    primitive = (u8*)g_GfxPrimCursor;
    SetSprt((SPRT*)primitive);
    primitive[4]            = 0x20;
    primitive[5]            = 0x20;
    primitive[6]            = 0x20;
    geom                    = (u8)icon * START08_ICON_STRIDE;
    *(s16*)(primitive + 8)  = x;
    *(s16*)(primitive + 10) = y;
    primitive[12]           = (u8) * (u16*)((u8*)D_801ED1FC + geom);
    primitive[13]           = (u8) * (u16*)((u8*)D_801ED1FE + geom);
    *(u16*)(primitive + 16) = *(u16*)((u8*)D_801ED200 + geom);
    *(u16*)(primitive + 18) = *(u16*)((u8*)D_801ED202 + geom);
    *(u16*)(primitive + 14) = (u16)(*(u16*)((u8*)D_801ED204 + geom) << 6);
    GFX_AddPrim((u8)palette, 20);
}
