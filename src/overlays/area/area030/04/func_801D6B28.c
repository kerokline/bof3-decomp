#include "area030_04.h"

/* Refreshes the AREA030 HUD panel state, clamps the two tracked x
 * positions into their visible ranges, then routes the two marker helpers. */
MATCH void func_801D6B28(s8 panel_kind) {
    s32 left_x;
    s32 right_x;

    Area_AddActor();
    func_801E0C80(0, 1);
    func_801E0DCC(0x15, 1, 0x32, 0x96);
    func_801E0DCC(0x16, 1, 0xBC, 0x96);
    func_801E0DCC(0x11, 1, 0x36, 0x9C);

    {
        u8* cell;
        u8* next;
        u8* mode_cell;
        s32 value;

        cell   = SP_REF(u8*, 0x44u);
        value  = *(s32*)(cell + 0x0Cu);
        left_x = (value < 0x39) ? 0x39 : ((value >= 0x7A) ? 0x79 : value);

        next                  = SP_REF(u8*, 0x44u);
        *(s32*)(cell + 0x0Cu) = left_x;

        value   = *(s32*)(next + 0x10u);
        right_x = (value < 0x41) ? 0x41 : ((value >= 0x95) ? 0x94 : value);

        mode_cell             = SP_REF(u8*, 0x44u);
        *(s32*)(next + 0x10u) = right_x;

        if ((*(s32*)(mode_cell + 0x10u) < *(s32*)(mode_cell + 0x0Cu)) ||
            (*(s32*)(mode_cell + 0x0Cu) + 0x20 < *(s32*)(mode_cell + 0x10u))) {
            func_801D3244((s16) * (s32*)(mode_cell + 0x0Cu), 0xB3, 0x20u, ((mode_cell[6] & 7u) << 1), 1u, 1);
        } else {
            func_801D3244((s16) * (s32*)(mode_cell + 0x0Cu), 0xB3, 0x20u, ((mode_cell[6] & 7u) << 1), 1u, 0);
        }
    }

    if ((panel_kind & BYTE_MASK) == 0) {
        func_801D2C34((s16) * (s16*)(SP_REF(u8*, 0x44u) + 0x10u), 0xB3, 0, 1u);
    } else {
        func_801D2C34((s16) * (s16*)(SP_REF(u8*, 0x44u) + 0x10u), 0xB3, 1, 1u);
    }
}
