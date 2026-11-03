#include "magic001_00.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

#include "overlays/bmagic/BMagic_RunStep.h"

INCLUDE_ASM(func_801EECC4);

INCLUDE_ASM(func_801EEF34);

#include "shared/Effect_StartPlaying.h"

MATCH void func_801EEFD8(void) {
    SYS_DISPATCH_BYTE(g_BMagicEffectFuncs, ((u8*)g_SpadWork)[1]);
}

INCLUDE_ASM(func_801EF01C);

INCLUDE_ASM(func_801EF0E8);

INCLUDE_ASM(func_801EF164);

INCLUDE_ASM(func_801EF1CC);

INCLUDE_ASM(func_801EF280);

INCLUDE_ASM(func_801EF324);

INCLUDE_ASM(func_801EF37C);

INCLUDE_ASM(func_801EF408);

INCLUDE_ASM(func_801EF468);

INCLUDE_ASM(func_801EF518);

INCLUDE_ASM(func_801EF5CC);

INCLUDE_ASM(func_801EF688);

MATCH void func_801EF72C(void) {
    BattleHandlerTable3 handlers;

    handlers = D_801EEC3C;
    SYS_DISPATCH_TASK(handlers.handlers, 1, g_SpadWork);
}

INCLUDE_ASM(func_801EF78C);

INCLUDE_ASM(func_801EFA14);

MATCH void Effect_StartPlaying_801EFA84(void) {
    u16* flags;

    BATTLE_RAISE_EFFECT_PLAYING();
}

MATCH void func_801EFAB8(void) {
    SYS_DISPATCH_TASK((g_BMagicEffectFuncs + 1), 1, g_SpadWork);
}

INCLUDE_ASM(func_801EFAFC);

INCLUDE_ASM(func_801EFBEC);

INCLUDE_ASM(func_801EFC54);

INCLUDE_ASM(func_801EFD28);

INCLUDE_ASM(func_801EFE38);

INCLUDE_ASM(func_801EFF28);

INCLUDE_ASM(func_801EFFCC);

INCLUDE_ASM(func_801F00A8);

INCLUDE_ASM(func_801F014C);

INCLUDE_ASM(func_801F0238);
