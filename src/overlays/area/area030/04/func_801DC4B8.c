#include "area030_04.h"

/* Submits mask `D_80145026` to `Party_RemoveItem` as mode 3; when it
 * reports failure, clears `D_80145026` and `D_80145027`. Always refreshes the
 * state through `func_801DDDBC`. */
MATCH void func_801DC4B8(void) {
    u8* flags;

    flags = &D_80145026;
    if (Party_RemoveItem(3, *flags, 1, 0) == 0) {
        *flags     = 0;
        D_80145027 = 0;
    }
    func_801DDDBC();
}
