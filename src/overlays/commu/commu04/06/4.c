#include "commu04_06.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

/* The commu04 overlay entry: the shared commu step byte selects the handler,
 * then the menu panels refresh while the game state is still zero. */
MATCH void func_801D0C04(void) {
    D_801D1750[D_801F294C]();
    if (g_GameStateIndex == GAME_REQUEST_IDLE) {
        Menu_RunPanelTasks();
    }
}

MATCH void func_801D0C5C(void) {
    SYS_DISPATCH_BYTE(D_801D1758, D_801F294D);
}

INCLUDE_ASM(func_801D0C98);

INCLUDE_ASM(func_801D0CF4);

INCLUDE_ASM(func_801D0D4C);

INCLUDE_ASM(func_801D11DC);

INCLUDE_ASM(func_801D12C8);

INCLUDE_ASM(func_801D1568);

INCLUDE_ASM(func_801D1628);

/* func_801D1670 */
#include "overlays/commu/Commu_AdvanceStep.h"

INCLUDE_ASM(func_801D16A4);
