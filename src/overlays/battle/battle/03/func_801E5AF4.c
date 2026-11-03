#include "battle_03.h"

MATCH void func_801E5AF4(void) {
    BattleEffectStage0Funcs table = g_BattleEffectStage0Funcs;

    table.handlers[D_801EC2E0->handler_index]();
}
