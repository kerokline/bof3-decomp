#include "engine/slus/slus.h"
#include <inline_c.h>

/* One 0x28-byte textured-quad record of the table at work->unk_50: clut index,
 * four vertices, the face normal and four packed uv pairs. */
typedef struct PanelPiece {
    s16 clut;    /* 0x00 */
    u16 v[4][3]; /* 0x02 */
    s16 n[3];    /* 0x1A */
    u16 uv[4];   /* 0x20 */
} PanelPiece;

/* projects the panel's textured-quad table through the GTE into
 * the primitive list, fills one sort-list row per quad and returns the quad
 * count.
 */
MATCH s8 func_8015AD00(PanelSortItem* sort_list) {
    CVECTOR color;
    STACK_PADS(VECTOR, 1); /* FAKE: retail keeps a dead 16-byte VECTOR slot at sp+0x18. */
    VECTOR      normal;
    VECTOR      vec;
    MATRIX      light;
    MATRIX      m;
    s32         z;
    u8          abr;
    u16         count;
    u16         tpage;
    u8*         prim;
    u8*         p;
    PanelPiece* piece;
    u16         otz;
    u16         vv;
    s32         i;

    vec = D_80149BF0;
    PushMatrix();
    count = (s8)g_SpadWork->range_54.table[0];
    func_8015B410(&m);
    SetRotMatrix(&m);
    SetTransMatrix(&m);
    if (g_SpadWork->unk_48 == 0) {
        normal.vx = normal.vy = normal.vz = g_SpadWork->unk_40;
        ScaleMatrix(&m, &normal);
    }
    light = m;
    func_8015B2AC(D_801481B8.m[0], &g_SpadWork->unk_64);
    func_8015B4B0(&light);
    SetLightMatrix(&D_801481B8);

    abr = g_SpadWork->range_54.table[3];
    if ((abr & 0x40) == 0) {
        abr = 2;
    }
    piece = (PanelPiece*)g_SpadWork->source_50;
    tpage = GetTPage(0, abr & 3, 704, 256);
    prim  = g_GfxPrimCursor;
    p     = prim;
    if ((u8*)(g_FrameBufferIndex * 0x9000 + PRIM_ARENA_BASE) < (prim + count * 0x28)) {
        return 0;
    }
    i = 0;
    if (count != 0) {
        do {
            SetPolyFT4((POLY_FT4*)p);

            vv = piece->v[0][0];
            MATCH_BARRIER(); /* FAKE: pin the vertex load into its retail store slot. */
            D_1F800014[0].vx = vv;
            MATCH_BARRIER(); /* FAKE: pin the vertex load into its retail store slot. */
            vv = piece->v[0][1];
            MATCH_BARRIER(); /* FAKE: pin the vertex load into its retail store slot. */
            SP_REF(u16, 0x16u) = vv;
            MATCH_BARRIER(); /* FAKE: pin the vertex load into its retail store slot. */
            vv = piece->v[0][2];
            MATCH_BARRIER(); /* FAKE: pin the vertex load into its retail store slot. */
            SP_REF(u16, 0x18u) = vv;
            MATCH_BARRIER(); /* FAKE: pin the vertex load into its retail store slot. */
            vv = piece->v[1][0];
            MATCH_BARRIER(); /* FAKE: pin the vertex load into its retail store slot. */
            D_1F800014[1].vx = vv;
            MATCH_BARRIER(); /* FAKE: pin the vertex load into its retail store slot. */
            vv = piece->v[1][1];
            MATCH_BARRIER(); /* FAKE: pin the vertex load into its retail store slot. */
            SP_REF(u16, 0x1Eu) = vv;
            MATCH_BARRIER(); /* FAKE: pin the vertex load into its retail store slot. */
            vv = piece->v[1][2];
            MATCH_BARRIER(); /* FAKE: pin the vertex load into its retail store slot. */
            SP_REF(u16, 0x20u) = vv;
            MATCH_BARRIER(); /* FAKE: pin the vertex load into its retail store slot. */
            vv = piece->v[2][0];
            MATCH_BARRIER(); /* FAKE: pin the vertex load into its retail store slot. */
            D_1F800014[2].vx = vv;
            MATCH_BARRIER(); /* FAKE: pin the vertex load into its retail store slot. */
            vv = piece->v[2][1];
            MATCH_BARRIER(); /* FAKE: pin the vertex load into its retail store slot. */
            SP_REF(u16, 0x26u) = vv;
            MATCH_BARRIER(); /* FAKE: pin the vertex load into its retail store slot. */
            vv = piece->v[2][2];
            MATCH_BARRIER(); /* FAKE: pin the vertex load into its retail store slot. */
            SP_REF(u16, 0x28u) = vv;
            MATCH_BARRIER(); /* FAKE: pin the vertex load into its retail store slot. */
            vv = piece->v[3][0];
            MATCH_BARRIER(); /* FAKE: pin the vertex load into its retail store slot. */
            D_1F800014[3].vx = vv;
            MATCH_BARRIER(); /* FAKE: pin the vertex load into its retail store slot. */
            vv = piece->v[3][1];
            MATCH_BARRIER(); /* FAKE: pin the vertex load into its retail store slot. */
            SP_REF(u16, 0x2Eu) = vv;
            MATCH_BARRIER(); /* FAKE: pin the vertex load into its retail store slot. */
            vv = piece->v[3][2];
            MATCH_BARRIER(); /* FAKE: pin the vertex load into its retail store slot. */
            SP_REF(u16, 0x30u) = vv;
            MATCH_BARRIER(); /* FAKE: pin the vertex load into its retail store slot. */
            normal.vx         = piece->n[0];
            normal.vy         = piece->n[1];
            normal.vz         = piece->n[2];
            *(u16*)(p + 0xC)  = piece->uv[0];
            *(u16*)(p + 0x14) = piece->uv[1];
            *(u16*)(p + 0x1C) = piece->uv[2];
            *(u16*)(p + 0x24) = piece->uv[3];

            gte_ldv0(&D_1F800014[0]);
            gte_rtps();
            gte_stsxy((u32*)(p + 8));
            gte_stszotz(&z);
            otz           = (u16)z;
            sort_list->z  = otz;
            sort_list->z0 = otz;

            gte_ldv0(&D_1F800014[1]);
            gte_rtps();
            gte_stsxy((u32*)(p + 0x10));
            gte_stszotz(&z);
            if (sort_list->z < z) {
                sort_list->z = z;
            }

            gte_ldv0(&D_1F800014[2]);
            gte_rtps();
            gte_stsxy((u32*)(p + 0x18));
            gte_stszotz(&z);
            if (sort_list->z < z) {
                sort_list->z = z;
            }

            gte_ldv0(&D_1F800014[3]);
            gte_rtps();
            gte_stsxy((u32*)(p + 0x20));
            gte_stszotz(&z);
            if (sort_list->z < z) {
                sort_list->z = z;
            }

            sort_list->work      = (u8*)g_SpadWork;
            sort_list->primitive = p;
            *(u8*)(p + 4)        = g_SpadWork->tint.bytes.unk_5D;
            *(u8*)(p + 5)        = g_SpadWork->tint.bytes.unk_5E;
            *(u8*)(p + 6)        = g_SpadWork->tint.bytes.unk_5F;
            if ((*(s8*)(g_SpadWork->range_54.table + 3) & 0x80) != 0) {
                VectorNormalS(&normal, D_1F800014);
                color.r  = g_SpadWork->tint.bytes.unk_5D;
                color.g  = g_SpadWork->tint.bytes.unk_5E;
                color.b  = g_SpadWork->tint.bytes.unk_5F;
                color.cd = *(u8*)(p + 7);
                NormalColorCol(D_1F800014, &color, (CVECTOR*)(p + 4));
            }

            *(u16*)(p + 0x16) = tpage;
            *(u16*)(p + 0xE)  = GetClut(piece->clut * 16, 483);
            SetSemiTrans(p, (abr >> 6) & 1);

            i++;
            sort_list++;
            p += 0x28;
            piece++;
        } while ((u16)i < count);
    }
    g_GfxPrimCursor = prim + count * 0x28;
    PopMatrix();
    return (s8)count;
}
