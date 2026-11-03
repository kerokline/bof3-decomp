#include "area030_04.h"

/* Draws a fixed frame, passes a bit selected by work byte 6 when
 * D_80145E93 is at least 3, then resets work fields and increments byte 1. */
MATCH void func_801D52D4(void) {
    u8* work;
    u8* state;
    u32 mask;

    func_801D9534(0x14, 0x12, 0x118, 0x13, 0);

    mask = 0;
    if (D_80145E93[0] >= 3) {
        mask = (1u << g_SpadWork->unk_06) & BYTE_MASK;
    }
    func_801D7C10(0x58, 0x28, mask);

    g_SpadWork->direction_08 = 0;
    work                     = (u8*)g_SpadWork;
    work[0xA]                = 0;
    state                    = (u8*)g_SpadWork;
    *(u32*)(work + 0x3C)     = 0;
    *(u32*)(work + 0x14)     = 0;
    *(u32*)(work + 0x20)     = 0;
    state[9]                 = 4;
    g_SpadWork->unk_01       = (u8)(g_SpadWork->unk_01 + 1);
}
