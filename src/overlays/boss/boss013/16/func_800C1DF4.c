#include "boss013_16.h"

MATCH void func_800C1DF4(void) {
    u8* work;

    work = g_SpadWork;
    if (work[0] & 0x80) {
        work[2]++;
    } else {
        FIELD(u32, work, 0x34) += 0x8000;
        func_8014D978();
        func_8014D978();
    }
}
