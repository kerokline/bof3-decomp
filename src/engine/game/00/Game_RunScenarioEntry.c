#include "game_00.h"

/* func_801A782C */
MATCH void Game_RunScenarioEntry(void) {
    g_SceneScenes[(s32)g_SceneState.scenario_id]->entry_00();
    Game_RunSceneUpdate();
}
