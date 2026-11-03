#include "game_00.h"

/* func_80199678 */
MATCH void Menu_DrawPanelCursor(void) {
    Menu_DrawCursorSprite(g_MenuPanelTaskCurrent->x, g_MenuPanelTaskCurrent->y, 0);
}
