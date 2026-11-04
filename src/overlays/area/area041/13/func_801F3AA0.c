#include "area041_13.h"

/* Follows func_801F3A48 (call args 3 and 4, values 0x1E and 0x28, else branch also clears *g_ScriptWorkRecord);
 * first difference: the else branch is one instruction short (retail keeps the value in v0 and has a nop after the lw). */
INCLUDE_ASM(func_801F3AA0);
