#include "area037_13.h"

MATCH void func_801F37F4(void) {
    s8 sel;

    sel = D_801490C7;
    if (sel == 0) {
        g_MessageRequest = 0xFFFF;
        D_80146867       = 0x64;
        func_801BE1B0(3);
    } else {
        g_MessageRequest = 0xBD;
        D_80146867       = 0;
    }
}
