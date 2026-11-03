#include "area085_13.h"

MATCH void func_801F3AF8(void) {
    g_SpadWork->flags_24 &= 0xFE;
    Area_FindSceneRecord(0x184);
    Actor_SelectScript(0);
    g_SpadWork->unk_2A = 1;
    g_SpadWork->flags_00 |= ACTOR_FLAG_STEP_MOVE;
}
