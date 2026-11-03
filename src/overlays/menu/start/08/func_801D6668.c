#include "start_08.h"

MATCH void func_801D6668(u8* first, u8* second) {
    u8 temp;

    temp    = *first;
    *first  = *second;
    *second = temp;
}
