#include "area041_13.h"

MATCH void func_801F3A48(void) {
    s32 sel;
    u8  value;

    sel              = D_801490C7;
    g_MessageRequest = 0xFFFF;
    if (sel == 0) {
        func_801BE1B0(1);
        value = 0xA;
    } else {
        func_801BE1B0(2);
        value = 0x14;
    }
    D_80146865 = value;
}
