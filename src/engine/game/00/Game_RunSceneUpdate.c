#include "game_00.h"

/* func_801A7BF0 */
MATCH void Game_RunSceneUpdate(void) {
    SYS_DISPATCH_BYTE(g_SceneStates, D_801448EA[0]);
}
