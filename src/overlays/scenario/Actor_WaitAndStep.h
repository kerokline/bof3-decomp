/* Counts the actor wait byte down, reloads it at zero and advances the handler
 * index. One definition shared by the two scenario overlays; every change here
 * must verify every member. */
/* func_801F8730 (scena07), func_801F8D18 (scena08) */
MATCH void Actor_WaitAndStep(void* actor) {
    u8 temp_v0_6;

    temp_v0_6              = FIELD(u8, actor, 0x2u) - 1;
    FIELD(u8, actor, 0x2u) = temp_v0_6;
    if (!(temp_v0_6 & BYTE_MASK)) {
        FIELD(u8, actor, 0x2u) = 0x20U;
        FIELD(u8, actor, 0x1u) = (u8)(FIELD(u8, actor, 0x1u) + 1);
    }
}
