#include "start_08.h"

extern u8 D_8014854C; /* local: u8 read; a sibling copy is s8 */
extern u8 D_801485B8; /* local: plain access; a sibling copy is volatile */

MATCH void func_801DB510(void) {
    D_801484E0             = 0;
    D_80148504.active      = 0;
    D_80148528             = 0;
    D_8014854C             = 0;
    g_BattleChoicePanel[0] = 0;
    D_80148594             = 0;
    D_801485B8             = 0;
}
