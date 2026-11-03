#ifndef GAME_SCRIPT_H
#define GAME_SCRIPT_H

#include "types.h"

typedef u8 (*ScriptFunc)(u8** cursor);

/* The script variable bytes at 0x80146864. A unit that stores through a
 * volatile view (etc/game/00) defines SCRIPT_VARS_VOLATILE before its first
 * include: a cast view of a volatile object hoists the address and moves bytes. */
#ifdef SCRIPT_VARS_VOLATILE
/* D_80146864 */
extern volatile u8 g_ScriptVars;
#else
/* D_80146864 */
extern u8 g_ScriptVars;
#endif

#endif
