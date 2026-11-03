#include "area030_04.h"

/* Builds the texture-page word for the selected AREA030 graphic and
 * appends its draw-mode primitive to the current ordering-table stream. */
MATCH void func_801E0C80(s32 graphic, s32 layer) {
    s32 tpage;

    if (GetGraphType() == 1) {
        tpage = ((*(s32*)(D_801E2384 + ((graphic & BYTE_MASK) << 4)) & 3) << 9) |
                ((*(s32*)(D_801E2388 + ((graphic & BYTE_MASK) << 4)) & 3) << 7) |
                ((*(s32*)(D_801E2390 + ((graphic & BYTE_MASK) << 4)) & 0x300) >> 3) |
                ((*(s32*)(D_801E238C + ((graphic & BYTE_MASK) << 4)) & 0x3FF) >> 6);
    } else if (GetGraphType() == 2) {
        tpage = ((*(s32*)(D_801E2384 + ((graphic & BYTE_MASK) << 4)) & 3) << 9) |
                ((*(s32*)(D_801E2388 + ((graphic & BYTE_MASK) << 4)) & 3) << 7) |
                ((*(s32*)(D_801E2390 + ((graphic & BYTE_MASK) << 4)) & 0x300) >> 3) |
                ((*(s32*)(D_801E238C + ((graphic & BYTE_MASK) << 4)) & 0x3FF) >> 6);
    } else {
        tpage = ((*(s32*)(D_801E2384 + ((graphic & BYTE_MASK) << 4)) & 3) << 7) |
                ((*(s32*)(D_801E2388 + ((graphic & BYTE_MASK) << 4)) & 3) << 5) |
                ((*(s32*)(D_801E2390 + ((graphic & BYTE_MASK) << 4)) & 0x100) >> 4) |
                ((*(s32*)(D_801E238C + ((graphic & BYTE_MASK) << 4)) & 0x3FF) >> 6) |
                ((*(s32*)(D_801E2390 + ((graphic & BYTE_MASK) << 4)) & 0x200) << 2);
    }

    GFX_SET_DRAW_MODE(tpage);
    GFX_AddPrim((u32)(u8)layer, 0x0C);
}
