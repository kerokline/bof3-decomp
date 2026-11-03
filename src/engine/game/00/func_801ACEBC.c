#include "game_00.h"

MATCH void func_801ACEBC(void) {
    Actor*              work;
    BattleHandlerTable5 table;

    work  = g_SpadWork;
    table = D_80195ED4;
    table.handlers[work->unk_04]();
}
