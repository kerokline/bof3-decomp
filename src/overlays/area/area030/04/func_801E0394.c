#include "area030_04.h"

/* While the scratchpad work-object gate byte is set, decrements it
 * and integrates the object's three velocity components into its three
 * position accumulators. */
MATCH void func_801E0394(void) {
    u8* spad;

    if (g_SpadWork->unk_09 != 0) {
        g_SpadWork->unk_09 = (u8)(g_SpadWork->unk_09 - 1u);
        spad               = (u8*)g_SpadWork;
        *(s32*)(spad + 0x34) += *(s32*)(spad + 0x0C);
        *(s32*)(spad + 0x38) += *(s32*)(spad + 0x10);
        *(u16*)(spad + 0x3E) = (u16)(*(u16*)(spad + 0x3E) + *(s32*)(spad + 0x14));
    }
}
