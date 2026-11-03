#include "game_00.h"

MATCH void func_801996A8(void) {
    g_MenuOptionHandlers[g_MenuPanelTaskCurrent->state]();
    func_801D7AD0(g_MenuPanelTaskCurrent);
}
