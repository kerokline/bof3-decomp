#include "engine/slus/slus.h"

/* replays the sound entry selected by cue_id unless cue_id is 0xFF.
 */
/* func_80161D74 */
MATCH void SND_ResumeBgm(s32 cue_id) {
    Snd_ToggleSequencePlayer(SsSepReplay, cue_id);
}
