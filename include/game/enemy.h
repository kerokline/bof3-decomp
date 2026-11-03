#ifndef GAME_ENEMY_H
#define GAME_ENEMY_H

/* The enemy, encounter and treasure-chest records from the world archives,
 * and their resistance and AI blocks. battle/battle/03, battle/battle/15 and etc/game/00 read
 * them; game/records.h owns the counts and strides.
 *
 * Layout: @source: wiki:data/records#area-data (`Encounter` is eight enemy
 * indexes and an appearance rate, 9 bytes). */

#include "types.h"
#include "game/records.h"

/* One byte per resistance slot. */
#define RES_SLOT_COUNT      9

#define ENEMY_AI_BLOCK_SIZE 0x10

/* Resistance arrays are nine byte slots; slot 8 has no element-mask bit.
 * Order: @source: wiki:data/records#area-data */
typedef enum ResistanceSlot {
    RES_SLOT_FIRE     = 0,
    RES_SLOT_FROST    = 1,
    RES_SLOT_ELECTRIC = 2,
    RES_SLOT_EARTH    = 3,
    RES_SLOT_WIND     = 4,
    RES_SLOT_HOLY     = 5,
    RES_SLOT_PSIONIC  = 6,
    RES_SLOT_STATUS   = 7,
    RES_SLOT_DEATH    = 8,
} ResistanceSlot;

typedef struct EnemyAiBlock {
    u8 condition;
    u8 parameters[ENEMY_AI_PARAMETER_COUNT];
    u8 skills[ENEMY_SKILL_COUNT];
} EnemyAiBlock;

ASSERT_SIZE(EnemyAiBlock, ENEMY_AI_BLOCK_SIZE);

typedef struct Enemy {
    u8           name[ENEMY_NAME_LENGTH];
    u16          enemy_id;
    u8           choice_ai;
    u8           unk_0B[3];
    u8           target_preference;
    u8           unk_0F;
    u16          zenny;
    u16          exp;
    u8           level;
    u8           unk_15[3];
    u8           initial_skills[ENEMY_SKILL_COUNT];
    u16          hp;
    u16          ap;
    u16          power;
    u16          defense;
    u16          agility;
    u16          intellect;
    u8           steal_item_index;
    u8           steal_item_type;
    u16          steal_rate;
    u8           drop_item_index;
    u8           drop_item_type;
    u16          drop_rate;
    EnemyAiBlock ai[ENEMY_AI_COUNT];
    u8           unk_74[4];
    u8           resistances[RES_SLOT_COUNT];
    u8           unk_81[7];
} Enemy;

ASSERT_SIZE(Enemy, ENEMY_STRIDE);

typedef struct Encounter {
    u8 enemy_indexes[ENCOUNTER_ENEMY_COUNT];
    u8 appearance_rate;
} Encounter;

ASSERT_SIZE(Encounter, ENCOUNTER_STRIDE);

#endif
