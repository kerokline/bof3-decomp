#include "start_08.h"

MATCH void func_801D4884(void) {
    u8* ptr = &D_801484BC;
    u8  value;

    D_801484BD = 6;
    D_801484BE = 9;
    D_801484BF = 2;
    *ptr       = 1;
    D_801484C0 = 0x14;
    D_801484C2 = -0x14;
    D_801484CC = 0;
    ptr += 0x24;
    D_801484E1 = 6;
    D_801484E2 = 0xD;
    D_801484E3 = 2;
    *ptr       = 1;
    D_801484E6 = -0x14;
    D_801484E4 = 0x40;
    D_801484EA = 0;
    {
        /* FAKE: keep the retail byte value in $a0 across both stores. */
        MATCH_REG(u8, byte, "a0");

        byte       = 0xFF;
        D_801484EB = byte;
        D_80148505 = 6;
        D_80148506 = 0xC;
        D_80148507 = 2;
        ptr += 0x24;
        *ptr = 1;
        ptr += 0xD8;
        D_80148510 = byte;
        D_80148511 = byte;
    }
    value      = *s_ChoiceMenuValues;
    D_80148508 = -0xC8;
    D_8014850A = 0x3E;
    D_801485DE = 0xA;
    D_8014850E = 0;
    D_8014850C = 0;
    D_8014850D = 0;
    D_80148514 = 0;
    D_80148516 = 0;
    D_801485DD = 6;
    D_8014850F = value;
    *ptr       = 0;
    D_801485E6 = 1;
    D_801485E7 = 1;
    D_80148625 = 6;
    D_80148626 = 0xE;
    D_80148627 = 0;
    /* FAKE: keep the updated record pointer for the final store. */
    MATCH_FAKE_OPAQUE(ptr);
    ptr[0x48] = 0;
}
