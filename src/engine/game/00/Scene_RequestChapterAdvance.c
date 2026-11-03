#include "game_00.h"

/* func_801A78F8 */
MATCH void Scene_RequestChapterAdvance(void) {
    g_SceneState.flags_01 |= 0x80;
}
