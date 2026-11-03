#include "engine/slus/slus.h"

/* returns 1 when the first byte of the record at cursor equals D_80146866.
 */
/* func_8015B9DC */
MATCH s32 Game_IsScriptVar2Equal(u8** cursor) {
    u8 result; /* the record byte, then the verdict */

    result = **cursor;
    if (D_80146866 != result) {
        result = 0;
        return result;
    }
    result = 1;
    return result;
}
