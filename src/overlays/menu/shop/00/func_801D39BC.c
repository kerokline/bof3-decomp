#include "shop_00.h"

/* Handler table for the shop's current menu state, indexed by the shared
 * shop-state byte D_80148651. */

MATCH void func_801D39BC(void) {
    SYS_DISPATCH_BYTE(D_801E52C4, D_80148651);
}
