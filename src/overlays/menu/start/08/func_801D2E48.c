#include "start_08.h"

MATCH void func_801D2E48(void) {
    u8* timer;
    u8  count;

    Menu_DrawClutStrip(D_80144953);
    timer = &D_80148654;
    if (TIMER_EXPIRED(*timer)) {
        count      = D_80148651;
        *timer     = 0;
        D_80148651 = count + 1;
    }
}
