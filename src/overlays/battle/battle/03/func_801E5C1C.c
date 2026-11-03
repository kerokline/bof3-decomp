#include "battle_03.h"

MATCH void func_801E5C1C(void) {
    BattleEffectStage3Funcs handlers;

    handlers = g_BattleEffectStage3Funcs;
    handlers.handlers[D_801EC2E0->handler_index]();
}
