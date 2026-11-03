#include "start_08.h"

MATCH void func_801D933C(u8* first, u8* second) {
    u8 temp;

    temp    = *first;
    *first  = *second;
    *second = temp;
}
