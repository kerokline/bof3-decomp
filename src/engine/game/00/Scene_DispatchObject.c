#include "game_00.h"

/* func_801A86D4 */
MATCH void Scene_DispatchObject(void* record) {
    g_SceneObjects[((Actor*)record)->callback_index](record, &g_SceneEventFlags);
}
