#ifndef OVERLAY_BOSS_BOSS055_16_H
#define OVERLAY_BOSS_BOSS055_16_H

/* The boss/boss055/16 overlay: one file per split function
 * and its data. Only this image includes the file. */

#include "overlays/boss/boss.h"
#include "overlays/battle/battle.h"

extern Callback                     D_800C184C[];
extern Callback                     D_800C356C[];
extern Callback                     D_800C359C[];
extern Callback                     D_800C35A4[];
extern Callback                     D_800C35AC[];
extern Callback                     D_800C35B4[];
extern Callback                     D_800C35CC[];
extern Callback                     D_800C35EC[];
extern Callback                     D_800C35F8[];
extern u16                          D_801463BE;
extern volatile BattleSelectionType D_801CA71C[];
extern EnemyBattler                 D_801EB630[];

void func_800C238C(u8 arg0, u8 arg1);
void func_800C2780(void);
void func_800C27E8(void);
void func_800C28E0(void);
void func_800C2948(void);
void func_800C2A40(void);
void func_800C2AA8(void);
void func_800C2BA0(void);
void func_800C2C78(void);
void func_800C2D2C(void);
void func_800C2E04(void);
void func_800C2ECC(void);
void func_800C2FA4(void);
void func_800C3284(void);

#endif
