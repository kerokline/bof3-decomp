#include "battle_15.h"

MATCH void func_800B0410(void) {
    BattlePanelTask* panel;

    func_800B0498();
    panel = BATTLE_PANEL_TASK;
    if (panel->cell_0A.mode == 0) {
        if (panel->x.signed_half < 0x142) {
            panel->x.signed_half += 0x20;
            return;
        }
        func_80158E20();
        return;
    }
    if (panel->x.signed_half < -0xBD) {
        func_80158E20();
        return;
    }
    panel->x.signed_half -= 0x20;
}
