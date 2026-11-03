#include "game_00.h"

/* func_801A7CAC */
MATCH void Scene_RunEventHandler(void) {
    SYS_DISPATCH_BYTE(g_SceneEvents, D_801448EB);
}
