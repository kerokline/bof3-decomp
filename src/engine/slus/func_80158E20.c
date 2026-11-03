#include "engine/slus/slus.h"

/* clears the two leading bytes and the state byte of the menu panel task.
 */
MATCH void func_80158E20(void) {
    g_MenuPanelTaskCurrent->unk_00[0] = 0;
    g_MenuPanelTaskCurrent->unk_00[2] = 0;
    g_MenuPanelTaskCurrent->state     = 0;
}
