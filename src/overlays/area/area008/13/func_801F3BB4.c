#include "area008_13.h"

MATCH void func_801F3BB4(void) {
    u8* p;
    u8  flag;

    p    = &WORLD00_AREA008_D_80146867;
    flag = *p;
    if (flag >= 0x10) {
        *p = (u8)(flag | 0x80);
        D_80146866 |= 0x80;
        SND_StopSequence(0, 2);
    } else {
        *p = (u8)(flag | 0x80);
        SND_StopSequence(0, 2);
    }
    Actor_Clear();
}
