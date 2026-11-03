#include "battle_03.h"

MATCH void func_801E5B8C(void) {
    BattleEffectStage1Funcs table;

    table = g_BattleEffectStage1Funcs;
    table.handlers[D_801EC2E0->handler_index]();
}
