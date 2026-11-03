#include "engine/slus/slus.h"

/* copies the handler bank into the local frame, then runs the entry
 * selected by the shared step byte D_801490C4, whose 0x80 base is rebased onto
 * the bank's 16 entries.
 */
/* func_801522F8 */
MATCH void Message_DispatchBankStep(void) {
    HandlerBank bank;

    bank = D_80149ACC;
    bank.handlers[D_801490BC.step_id - 0x80]();
}
