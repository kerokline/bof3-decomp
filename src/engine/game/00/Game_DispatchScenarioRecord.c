#include "game_00.h"

/* func_801A7878 */
MATCH void Game_DispatchScenarioRecord(void* object) {
    Actor* record;

    record = (Actor*)object;
    if (record->unk_7C & 0x4000) {
        Scene_DispatchObject(record);
    } else {
        g_SceneScenes[(s32)g_SceneState.scenario_id]->entry_04(record);
    }
    record->callback_index = 0xFF;
}
