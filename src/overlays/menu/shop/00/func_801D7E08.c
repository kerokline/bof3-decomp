#include "shop_00.h"

MATCH void func_801D7E08(u8* first, u8* second) {
    u8 temp;

    temp    = *first;
    *first  = *second;
    *second = temp;
}
