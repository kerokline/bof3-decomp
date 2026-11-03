/* Reloads the effect timer (work byte 0x09) with the value func_800AFF98 returns
 * and advances the effect step (work byte 0x02). One definition shared by the
 * bmagic effect modules; every change here must verify every member. */
/* Effect_ReloadTimerAndStep (magic004, magic008, magic021, magic065, magic154, magic161), Effect_ReloadTimerAndStep_801F17BC (magic008) */
/* The statements of Effect_ReloadTimerAndStep; each member has no locals. */
#define BMAGIC_RELOAD_TIMER_AND_STEP()          \
    g_SpadWork->unk_09 = func_800AFF98();       \
    g_SpadWork->unk_02 = g_SpadWork->unk_02 + 1

MATCH void Effect_ReloadTimerAndStep(void) {
    BMAGIC_RELOAD_TIMER_AND_STEP();
}
