#include "engine/slus/slus.h"

/* stores operand[1] in g_ScriptVars[operand[0] >> 2 & 3] and returns 1.
 */
/* func_8015BA2C */
MATCH s32 Game_SetScriptVar(u8* operand) {
    g_ScriptVars[(operand[0] & 0xC) >> 2] = operand[1];
    return 1;
}
