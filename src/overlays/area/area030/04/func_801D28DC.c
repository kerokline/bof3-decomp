#include "area030_04.h"

/* Selects the load mode from the scheduled-area flag, then copies the
 * selected AREA030 table row into the scratch record's probe fields and runs
 * the per-frame tail. */
MATCH void func_801D28DC(void) {
    FishingState* work;

    if (D_8014421C < 0) {
        Actor_RequestScript(2);
    } else {
        Actor_RequestScript(3);
    }

    work                        = FISHING_STATE;
    work->motion_34.unk_34      = *(s32*)(D_801468BC + D_801E3208 * 152);
    work->y_38.pos_y            = *(s32*)(D_801468C0 + D_801E3208 * 152);
    work->bounce_3C.half.key_3E = *(u16*)(D_801468C6 + D_801E3208 * 152);

    func_8014D978();
    func_801E084C();
}
