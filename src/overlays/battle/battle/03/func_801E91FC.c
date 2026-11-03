#include "battle_03.h"

MATCH void func_801E91FC(void) {
    BattleHandlerTable3 handlers;

    handlers = D_801D0FAC;
    handlers.handlers[((u8*)g_MenuPanelTaskCurrent)[3]]();
}
