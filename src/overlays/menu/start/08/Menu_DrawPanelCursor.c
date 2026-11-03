#include "start_08.h"

/* func_801EA198 */
MATCH void Menu_DrawPanelCursor(void) {
    Menu_DrawCursorSprite(g_MenuPanelTaskCurrent->x, g_MenuPanelTaskCurrent->y, 0);
}
