#include "boss035_16.h"

/* func_800C1C3C */
MATCH void Boss_EndBattle(void) {
    u16* flags;

    BATTLE_RAISE_STATE(BATTLE_STATE_WINDOW_BUSY);
    UI_SetMode(4);
}
