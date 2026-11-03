#include "game_00.h"

/* func_80197A24 */
MATCH void Game_RunBattleState(void) {
    Callback* handlers;
    u16       state;

    handlers = (Callback*)g_GameModeHandlers;
    state    = g_GameEntrySubstate;
    handlers[state]();
}
