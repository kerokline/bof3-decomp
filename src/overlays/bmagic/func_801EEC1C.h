/* Runs the step handler that the spad-work step_01 byte selects.
 * One definition shared by the images that include it;
 * every change here must verify every member. */
/* func_801EEC1C (magic062), func_801EEC1C (magic082), func_801EEC1C (magic086), func_801EEC1C (magic167) */
MATCH void func_801EEC1C(void) {
    BmagicEffectFuncs handlers;

    BMAGIC_DISPATCH_STEP_HANDLERS(D_801EEC04, step_01);
}
