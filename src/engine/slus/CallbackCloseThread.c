#include "engine/slus/slus.h"

/* clears one callback slot and closes its thread inside the scheduler
 * critical section.
 */
/* func_8014B900 */
MATCH void CallbackCloseThread(s32 slot_index) {
    D_80143B40[slot_index].state = 0;
    EnterCriticalSection();
    CloseTh(D_80143B40[slot_index].thread_id);
    ExitCriticalSection();
}
