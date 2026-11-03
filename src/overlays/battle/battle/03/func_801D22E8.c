#include "battle_03.h"

MATCH void func_801D22E8(void) {
    u8 value;

    value = g_BattlePanelWidths[g_BattlePanelSlot];
    if (value != 0) {
        g_BattlePanelWidths[g_BattlePanelSlot] = value - 2;
    } else {
        g_BattleSubStep += 1;
    }
    func_801D8450(g_BattlePanelSlot);
    func_801D750C(D_80148358, D_8014835A);
    func_801D7A40(D_8014837C, D_8014837E);
}
