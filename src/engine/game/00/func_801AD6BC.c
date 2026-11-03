#include "game_00.h"

MATCH void func_801AD6BC(void) {
    Actor*            work;
    GameHandlerTable6 table;

    work  = g_SpadWork;
    table = D_80195F44;
    table.handlers[work->unk_04]();
}
