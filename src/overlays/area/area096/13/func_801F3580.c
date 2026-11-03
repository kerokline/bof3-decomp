#include "area096_13.h"

MATCH void func_801F3580(void) {
    u8* work;

    work = SP_REF(u8*, 0x44);
    if (work[8] == 7) {
        work[8] = 3;
    } else {
        work[8] = 7;
    }
}
