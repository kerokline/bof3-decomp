#ifndef OVERLAY_SCENARIO_SCENA10_00_H
#define OVERLAY_SCENARIO_SCENA10_00_H

/* The scenario/scena10/00 overlay's local declarations. Only this image
 * includes the file. */

#include "overlays/scenario/scenario.h"

#define g_ScriptVars (*(s8*)&g_ScriptVars)

extern u32       D_801F6C00;
extern Callback  D_801FE820[];
extern Callback  D_801FE8F4[];
extern Callback  D_801FE900[];
extern SceneFunc D_801FE97C[];

extern Callback D_801FE80C[];

#endif
