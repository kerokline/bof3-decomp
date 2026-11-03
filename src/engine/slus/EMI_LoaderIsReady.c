#include "engine/slus/slus.h"

/* returns true only when the EXE-side EMI loader reached ready
 * state 3.
 */
/* func_80162D00 */
MATCH s32 EMI_LoaderIsReady(void) {
    volatile const u8* emi_state_base;

    emi_state_base = ((volatile const u8*)&D_80140000);
    return emi_state_base[0x6494] == 3u;
}
