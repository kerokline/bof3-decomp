#include "area049_13.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

MATCH void func_8011700C(void) {
    /* Retail reads the handler record from the entry $v0; the uninitialised local reads it. */
    u8* entity;

    SYS_DISPATCH_TASK(D_8011818C, 1, entity);
}

INCLUDE_ASM(func_80117048);

MATCH void func_801170A4(void) {
    if (!(func_80117410() & BYTE_MASK)) {
        Actor_Clear();
    }
}

INCLUDE_ASM(func_801170D8);

INCLUDE_ASM(func_801172D0);

INCLUDE_ASM(func_80117410);

INCLUDE_ASM(func_80117514);

INCLUDE_ASM(func_8011759C);

MATCH void func_80117610(void) {
    SYS_DISPATCH_TASK(D_8011819C, 1, g_SpadWork);
    func_80117900();
}

INCLUDE_ASM(func_8011765C);

INCLUDE_ASM(func_801176B8);

INCLUDE_ASM(func_80117768);

INCLUDE_ASM(func_80117818);

INCLUDE_ASM(func_80117864);

#include "overlays/area/Area_FindFreeWorkRow.h"

INCLUDE_ASM(func_80117900);

MATCH void func_80117A30(void) {
    SYS_DISPATCH_BYTE(D_801181AC, SP_REF(u8*, 0x44)[0x2]);
}

INCLUDE_ASM(func_80117A74);

INCLUDE_ASM(func_80117ACC);

INCLUDE_ASM(func_80117B60);

MATCH void func_80117BF4(void) {
    SYS_DISPATCH_BYTE(D_801181B4, SP_REF(u8*, 0x44)[0x2]);
}

MATCH void func_80117C38(void) {
    Scene_AdvanceActorState();
}

INCLUDE_ASM(func_80117C58);

INCLUDE_ASM(func_80117DF0);

INCLUDE_ASM(func_80117E78);
