#include "boss025_13.h"

MATCH void Boss_EndBattle2(void) {
    u16* flags;

    BATTLE_RAISE_STATE(BATTLE_STATE_WINDOW_BUSY);
    UI_SetMode(4);
}
