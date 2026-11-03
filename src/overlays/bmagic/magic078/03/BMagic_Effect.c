#include "magic078_03.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

INCLUDE_ASM(func_801EEC04);

INCLUDE_ASM(func_801EECFC);

#include "overlays/bmagic/Effect_PlayOnIdleTick.h"

MATCH void func_801EEEE4(void) {
    SYS_DISPATCH_BYTE(g_BMagicEffectFuncs, ((u8*)g_SpadWork)[1]);
}

INCLUDE_ASM(func_801EEF28);

INCLUDE_ASM(func_801EF08C);

#include "overlays/bmagic/Effect_CountDownAndStep.h"

INCLUDE_ASM(func_801EF12C);

INCLUDE_ASM(func_801EF1CC);

INCLUDE_ASM(func_801EF228);

INCLUDE_ASM(func_801EF278);

INCLUDE_ASM(func_801EF2CC);

INCLUDE_ASM(func_801EF318);

INCLUDE_ASM(func_801EFE14);

/* Follows BMAGIC_PROJECT_ACTOR_MATRIX (bmagic.h), but the work pointer lives in $a1 and a
 * type-13 branch loads a word into the rotation before the projection. */
INCLUDE_ASM(func_801EFEB8);

INCLUDE_ASM(func_801EFF84);

INCLUDE_ASM(func_801F00A0);

INCLUDE_ASM(func_801F00EC);

INCLUDE_ASM(func_801F014C);

INCLUDE_ASM(func_801F01D0);

INCLUDE_ASM(func_801F0230);

INCLUDE_ASM(func_801F02B4);

INCLUDE_ASM(func_801F02FC);

#include "overlays/bmagic/Effect_SetActorMatrix.h"
