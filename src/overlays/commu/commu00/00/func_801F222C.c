#include "commu00_00.h"

MATCH void func_801F222C(void) {
    if (g_GameStateIndex != 2) {
        g_AreaWalkFlags |= AREA_WALK_BUSY_ALL;
        EMI_LoaderStreamInitSlot(EMI_SLOT_COMMU04);
        FAIRY_EVENT_STEP = FAIRY_EVENT_STEP + 1;
    }
}
