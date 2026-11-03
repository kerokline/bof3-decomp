#include "game_00.h"

/* func_801984AC */
MATCH void Game_RunFishingState(void) {
    Callback* handlers;
    u16       state;

    handlers = (Callback*)g_GameSubstateHandlers;
    state    = g_GameEntrySubstate;
    handlers[state]();
}
