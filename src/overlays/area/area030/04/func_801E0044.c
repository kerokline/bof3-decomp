#include "area030_04.h"

/* Integrates the AREA030 work record's two velocity pairs into its
 * position words and counts down the timer byte; when the timer reaches zero it
 * snaps both positions to the sign bit, clears the velocity words and raises the
 * work state. */
MATCH void func_801E0044(void) {
    u8* record;
    u8* record2;
    u8  timer;
    u8  state;
    /* FAKE: retail reuses v0 as the halfword accumulator. */
    MATCH_FAKE_PIN(u16, value, "v0");
    u8* work3;

    record                 = (u8*)g_SpadWork;
    *(u32*)(record + 0x34) = *(u32*)(record + 0x34) + *(u32*)(record + 0xC);
    timer                  = record[9];
    record[9]              = timer - 1;
    record2                = (u8*)g_SpadWork;
    *(u32*)(record + 0x38) = *(u32*)(record + 0x38) + *(u32*)(record + 0x10);
    state                  = 1;
    if (record2[9] == 0) {
        record2[1] = state;
        work3      = (u8*)g_SpadWork;
        value      = *(u16*)(record2 + 0x34);
        value &= 0x8000;
        *(u16*)(record2 + 0x34) = value;
        *(u32*)(record2 + 0xC)  = 0;
        *(u32*)(record2 + 0x10) = 0;
        value                   = *(u16*)(record2 + 0x38);
        value &= 0x8000;
        *(u16*)(record2 + 0x38) = value;
        work3[2]                = 0;
    }
    func_8014D978();
}
