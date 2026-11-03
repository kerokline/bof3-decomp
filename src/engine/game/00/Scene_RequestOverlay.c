#include "game_00.h"

/* func_801A7804 */
MATCH void Scene_RequestOverlay(void) {
    EMI_LoaderStreamInitSlot(g_SceneState.scenario_id + EMI_SLOT_SCENA);
}
