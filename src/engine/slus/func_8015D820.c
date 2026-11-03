#include "engine/slus/slus.h"

/* TODO
 */
MATCH void func_8015D820(u16 cue_id, u16 index) {
    if (D_80145EC6 <= g_Actors[index].x.part.integer + 22 && D_80145EC6 >= g_Actors[index].x.part.integer - 22 &&
        D_80145ECA <= g_Actors[index].y.part.integer + 22 && D_80145ECA >= g_Actors[index].y.part.integer - 22) {
        D_8018B3D8 = D_80182308[0];
        D_8018B3DC = D_80182308[0];
        SND_PlayCue(cue_id);
    }
    if (D_80145EC6 <= g_Actors[index].x.part.integer + 18 && D_80145EC6 >= g_Actors[index].x.part.integer - 18 &&
        D_80145ECA <= g_Actors[index].y.part.integer + 18 && D_80145ECA >= g_Actors[index].y.part.integer - 18) {
        D_8018B3D8 = D_80182308[0];
        D_8018B3DC = D_80182308[0];
        SND_PlayCue(cue_id);
    }
    if (D_80145EC6 <= g_Actors[index].x.part.integer + 12 && D_80145EC6 >= g_Actors[index].x.part.integer - 12 &&
        D_80145ECA <= g_Actors[index].y.part.integer + 12 && D_80145ECA >= g_Actors[index].y.part.integer - 12) {
        D_8018B3D8 = D_801822EA;
        D_8018B3DC = D_801822EA;
        SND_PlayCue(cue_id);
    }
    if (D_80145EC6 <= g_Actors[index].x.part.integer + 8 && D_80145EC6 >= g_Actors[index].x.part.integer - 8 &&
        D_80145ECA <= g_Actors[index].y.part.integer + 8 && D_80145ECA >= g_Actors[index].y.part.integer - 8) {
        D_8018B3D8 = D_801822CA;
        D_8018B3DC = D_801822CA;
        SND_PlayCue(cue_id);
    }
    if (D_80145EC6 <= g_Actors[index].x.part.integer + 6 && D_80145EC6 >= g_Actors[index].x.part.integer - 6 &&
        D_80145ECA <= g_Actors[index].y.part.integer + 6 && D_80145ECA >= g_Actors[index].y.part.integer - 6) {
        D_8018B3D8 = D_801822AA;
        D_8018B3DC = D_801822AA;
        SND_PlayCue(cue_id);
    }
    if (D_80145EC6 <= g_Actors[index].x.part.integer + 2 && D_80145EC6 >= g_Actors[index].x.part.integer - 2 &&
        D_80145ECA <= g_Actors[index].y.part.integer + 2 && D_80145ECA >= g_Actors[index].y.part.integer - 2) {
        D_8018B3D8 = D_80182290[0];
        D_8018B3DC = D_80182290[0];
        SND_PlayCue(cue_id);
    }
}
