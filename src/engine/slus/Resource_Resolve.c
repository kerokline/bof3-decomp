#include "engine/slus/slus.h"

/* resolves a resource id to its in-RAM address through the loader-written
 * table at 0x8001A000.
 */
/* func_801502D0 */
MATCH u32 Resource_Resolve(u32 resource_id) { /* func_801502D0 */
    u8*           base;
    volatile u32* entry;
    u8*           ptr;
    u16           offset;

    base   = (u8*)RESOURCE_TABLE_BASE;
    entry  = (volatile u32*)(base + ((resource_id >> 12) & 0xC));
    ptr    = base + *entry;
    offset = *(u16*)(ptr + ((resource_id & 0x3FFF) * 2));
    return (u32)(ptr + offset);
}
