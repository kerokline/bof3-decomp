#include "area134_13.h"

MATCH void func_801F31B8(void) {
    u8* work;
    u8* flag;

    work    = (u8*)g_SpadWork;
    flag    = &D_80146865;
    work[1] = 0;
    if (*flag == GAME_NONE || D_80146866 == 0x80) {
        *flag = 0;
    }
}
