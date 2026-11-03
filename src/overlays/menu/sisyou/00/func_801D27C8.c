#include "sisyou_00.h"

/* Panel-lock flag owned by the main executable. */

MATCH void func_801D27C8(void) {
    Message_StartAreaMessage((s16)(D_801D41BC[D_801448ED] + 5));
    g_GameStateIndex = 2;
    g_MasterSubStep++;
}
