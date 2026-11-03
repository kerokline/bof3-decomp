#include "area095_13.h"

MATCH void func_801F35F0(void) {
    u8* work;

    work = SP_REF(u8*, 0x44);
    if (work[8] == 7) {
        work[8] = 3;
    } else {
        work[8] = 7;
    }
}
