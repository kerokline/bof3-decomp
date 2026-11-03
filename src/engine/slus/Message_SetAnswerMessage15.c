#include "engine/slus/slus.h"

/* stores table entry D_801490C7 of the D_8017F664 row in g_MessageRequest.
 */
/* func_801526C8 */
MATCH void Message_SetAnswerMessage15(void) {
    g_MessageRequest = D_8017F628[30 + D_801490BC.selection_index];
}
