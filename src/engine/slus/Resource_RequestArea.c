#include "engine/slus/slus.h"

/* resolves the requested area resource into the shared handle pair,
 * latches the raw request id in the area request slot, then resets the
 * front-end state block.
 */
/* func_80150284 */
MATCH void Resource_RequestArea(s32 request_id) { /* func_80150284 */
    u32 handle;

    handle           = Resource_Resolve(request_id & HALF_MASK);
    D_801490AC       = handle;
    D_801490B0       = (u8*)handle;
    g_MessageRequest = request_id;
    UI_ResetMessage();
}
