#include "engine/slus/slus.h"

/* sets bit 6 of the three boot flag bytes.
 */
/* func_8015C100 */
MATCH void Party_HideBattlers(void) {
    g_BattlePartyBattlers[0].flags_00 |= ACTOR_FLAG_HIDDEN;
    g_BattlePartyBattlers[1].flags_00 |= ACTOR_FLAG_HIDDEN;
    g_BattlePartyBattlers[2].flags_00 |= ACTOR_FLAG_HIDDEN;
}
