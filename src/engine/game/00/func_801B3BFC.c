#include "game_00.h"

MATCH void func_801B3BFC(void) {
    /* Non-volatile view is byte-required: the volatile read emits an extra
     * andi and grows the function 64 -> 68 bytes. */
    if (LOHU(g_GameAreaId) == 0x68) {
        func_801F45BC();
        return;
    }
    func_801F4B00();
}
