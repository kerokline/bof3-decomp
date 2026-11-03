#include "engine/slus/slus.h"

/* resolves the effect group's entry in the s8 table at g_SelectionFxVoices
 * and forwards it, with the caller's effect id, to SsSepStop.
 */
/* func_8015D404 */
MATCH void SND_StopSequence(s32 group, s16 sequence) {
    SsSepStop(g_SelectionFxVoices[group & HALF_MASK], sequence);
}
