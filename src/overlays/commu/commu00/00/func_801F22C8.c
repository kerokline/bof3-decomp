#include "commu00_00.h"

/* The three commu list counts, zeroed together at commu00 init (Fairy_VillageInit):
 * D_80145E44 counts the byte list at D_80145E30, g_FairyVillagePendingQueueCount
 * the byte list at D_80145E48, and g_FairyVillageUpdateCount the 2-byte rows at D_80145E60. */

MATCH void func_801F22C8(void) {
    if (D_80145E44 == 0 && g_FairyVillagePendingQueueCount == 0 && g_FairyVillageUpdateCount == 0) {
        D_801448EB = 6;
    } else {
        g_AreaWalkFlags |= AREA_WALK_BUSY_ALL;
        EMI_LoaderStreamInitSlot(EMI_SLOT_COMMU05);
        FAIRY_EVENT_STEP = FAIRY_EVENT_STEP + 1;
    }
}
