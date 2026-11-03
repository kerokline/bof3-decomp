#include "game_00.h"

/* func_80197378 */
MATCH void Game_RunFieldState(void) {
    u32* counter;

    Game_RunScenarioEntry();
    Area_RunFrame();

    switch (g_GameStateIndex) {
        case 0:
            break;
        case 1:
            UI_SetMode(2);
            func_80198BC4(0);
            g_GameEntryState    = 3;
            g_GameEntrySubstate = 0;
            break;
        case 2:
            g_GameEntryState = 4;
            break;
        case 3:
            g_BattleMode        = 0;
            g_BattleStep        = 0;
            g_BattleSubStep     = 0;
            D_80145E9B          = 0;
            D_80145FDB          = 0;
            D_8014611B          = 0;
            counter             = &g_BattleCount;
            g_GameEntryState    = 5;
            g_GameEntrySubstate = 0;
            (*counter)++;
            break;
        case 4:
            g_GameEntryState = 6;
            break;
        case 5: {
            u8 selection;

            g_AreaWalkFlags |= AREA_WALK_ENTRY_PENDING;
            selection = g_SndBgmId;
            if (selection != GAME_NONE && g_GamePrevSelection != selection) {
                SND_StartDecrescendo(g_SelectionCues[selection * 4], D_80181EBB[selection * 4], 100, 16);
            }
            if (g_GameEntryMode != GAME_NONE) {
                UI_SetMode(g_GameEntryMode);
                func_80198BC4(0);
            }
            selection = g_SndBgmId;
            if (selection != GAME_NONE && g_GamePrevSelection != selection) {
                SND_StopSequence(g_SelectionCues[selection * 4], D_80181EBB[selection * 4]);
            }
            g_GameEntryState = 1;
            break;
        }
        case 6:
            D_80148650          = 6;
            D_8014865C          = -1;
            D_80148651          = 0;
            D_80148652          = 0;
            g_GameEntryState    = 7;
            g_GameEntrySubstate = 0;
            break;
        case 7:
            g_GameEntryState    = 9;
            g_GameEntrySubstate = 0;
            D_80148650          = 0;
            D_80148651          = 0;
            D_80148652          = 0;
            break;
        case 8:
            g_GameEntryState    = 10;
            g_GameEntrySubstate = 0;
            D_80148650          = 0;
            D_80148651          = 0;
            D_80148652          = 0;
            break;
        case 9:
            D_8014626C       = 1;
            D_8014626D       = 0;
            D_8014626E       = 0;
            D_8014626F       = 0;
            D_80146270       = 0;
            g_GameEntryState = 11;
            break;
    }
}
