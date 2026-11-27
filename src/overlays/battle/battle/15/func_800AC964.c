#include "battle_15.h"

/* One row of the enemy panel list: an enemy id and the live slots still to place. */
typedef struct BattleEnemyGroup {
    s16 id;
    s16 count;
} BattleEnemyGroup;

/* Groups the live enemy slots by enemy id, puts the largest group first, then opens one panel per
 * placed enemy down the column the battle's scroll direction selects. */
MATCH void func_800AC964(void) {
    BattleEnemyGroup groups[8];
    BattleEnemyGroup swap;
    u8               i;
    u8               j;
    u8               k;
    u8               total;
    u8               found;
    u8               panels;
    s32              panel;
    s32              x;
    s16              y;
    s16              saved_y;

    total = 0;
    for (i = 0; i < 8; i++) {
        groups[i].id = -1;
    }
    for (i = 0; i < g_Battle.enemy_count; i++) {
        if (g_BattleEnemyBattlers[i].header.flags & 1) {
            found = 0;
            for (j = 0; j < total; j++) {
                if (groups[j].id == g_BattleEnemyBattlers[i].enemy_id.byte.type) {
                    found           = 1;
                    groups[j].count = groups[j].count + 1;
                    break;
                }
            }
            if (!found) {
                groups[total].id    = g_BattleEnemyBattlers[i].enemy_id.byte.type;
                groups[total].count = 1;
                total               = total + 1;
            }
        }
    }
    if (g_Battle.enemy_count >= 2) {
        for (j = 1; j < total; j++) {
            for (i = j - 1; i < total - 1; i++) {
                if (groups[i].count < groups[i + 1].count) {
                    swap          = groups[i];
                    groups[i]     = groups[i + 1];
                    groups[i + 1] = swap;
                }
            }
        }
    }
    x      = D_800B51E8[g_Battle.scroll_dir][0];
    y      = D_800B51E8[g_Battle.scroll_dir][1];
    panels = 0;
    /* The enemy panels take the slots from 0xC down, one per enemy the side shows. */
    if (g_Battle.scroll_dir >= 2) {
        for (i = 0; groups[i].id != -1; i++) {
            k       = 0;
            j       = groups[i].count;
            y       = y - 0x15;
            y       = y - ((j - 1) << 3);
            saved_y = y;
            for (; k < g_Battle.enemy_count; k++) {
                if (j == 0) {
                    break;
                }
                if (groups[i].id == g_BattleEnemyBattlers[k].enemy_id.byte.type) {
                    groups[i].count = groups[i].count - 1;
                    UI_PanelOpenTask(0xC - panels, 3);
                    j     = j - 1;
                    panel = panels;
                    panels++;
                    panel                                   = 0xC - panel;
                    g_UIPanelTasks[panel].mode              = 4;
                    g_UIPanelTasks[panel].state             = 0;
                    (&g_UIPanelTasks[panel])->u.addr.unk_10 = x;
                    g_UIPanelTasks[panel].pos.vx            = x;
                    (&g_UIPanelTasks[panel])->u.addr.unk_12 = y;
                    g_UIPanelTasks[panel].pos.vy            = y;
                    y                                       = y + 8;
                    g_UIPanelTasks[panel].unk_0A            = k + 3;
                    g_UIPanelTasks[panel].unk_08            = 0;
                    g_UIPanelTasks[panel].unk_09            = 0;
                }
            }
            y = saved_y - 2;
        }
    } else {
        i = 0;
        while (1) {
            y = y + 0x15;
            y = y + (groups[i].count - 1) * 8;
            i++;
            /* The last group ends the list. */
            if (groups[i].id == -1) {
                break;
            }
            y = y + 2;
        }
        for (i = 0; groups[i].id != -1; i++) {
            k       = 0;
            j       = groups[i].count;
            y       = y - 0x15;
            y       = y - ((j - 1) << 3);
            saved_y = y;
            for (; k < g_Battle.enemy_count; k++) {
                if (j == 0) {
                    break;
                }
                if (groups[i].id == g_BattleEnemyBattlers[k].enemy_id.byte.type) {
                    groups[i].count = groups[i].count - 1;
                    UI_PanelOpenTask(0xC - panels, 3);
                    j     = j - 1;
                    panel = panels;
                    panels++;
                    panel                                   = 0xC - panel;
                    g_UIPanelTasks[panel].mode              = 4;
                    g_UIPanelTasks[panel].state             = 0;
                    (&g_UIPanelTasks[panel])->u.addr.unk_10 = x;
                    g_UIPanelTasks[panel].pos.vx            = x;
                    (&g_UIPanelTasks[panel])->u.addr.unk_12 = y;
                    g_UIPanelTasks[panel].pos.vy            = y;
                    y                                       = y + 8;
                    g_UIPanelTasks[panel].unk_0A            = k + 3;
                    g_UIPanelTasks[panel].unk_08            = 0;
                    g_UIPanelTasks[panel].unk_09            = 0;
                }
            }
            y = saved_y - 2;
        }
    }
}
