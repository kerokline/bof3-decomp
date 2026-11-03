#include "battle_03.h"

MATCH void func_801E6AA0(void) {
    BattleHandlerTable3 handlers;

    handlers = D_801D0F38;
    handlers.handlers[g_SpadWork->step_01]();
    if (ACTOR_IN_USE(*g_SpadWork)) {
        Area_AddActor();
    }
}
