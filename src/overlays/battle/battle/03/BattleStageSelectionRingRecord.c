#include "battle_03.h"

/* func_801DE8C0 */
MATCH void BattleStageSelectionRingRecord(s8 slot_index, s8 record_kind, u32 resource_handle) {
    u8  i;
    int off;

    i                     = D_801EC328;
    D_801EB5B0[(u8)i * 8] = (u8)slot_index;
    i                     = D_801EC328;
    D_801EB5B1[(u8)i * 8] = (u8)record_kind;
    i                     = D_801EC328;
    off                   = (int)(u8)i * 2;
    D_801EB5B4[off]       = resource_handle;
    D_801EC328            = (i + 1u) & 0x0Fu;
}
