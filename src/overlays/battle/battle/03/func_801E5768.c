#include "battle_03.h"

MATCH void func_801E5768(void) {
    if (((g_BattleResult & BATTLE_RESULT_DEFEAT) != 0u) && (D_80143F04 == 0xBD)) {
        D_80146874 = 1u;
        D_80146875 = 0x19u;
        Game_SetScriptActive();
        func_801DDF28();
    }
}
