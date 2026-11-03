#ifndef INCLUDE_ASM_H
#define INCLUDE_ASM_H

#if !defined(M2CTX) && !defined(PERMUTER)

#ifndef ASM_DIR
#error "INCLUDE_ASM needs -DASM_DIR=\"asm/<target>\" from the build"
#endif

#ifndef INCLUDE_ASM
#define INCLUDE_ASM(NAME)                                \
    __asm__(".section .text\n"                           \
            "    .set noat\n"                            \
            "    .set noreorder\n"                       \
            "    .include \"" ASM_DIR "/" #NAME ".s\"\n" \
            "    .set reorder\n"                         \
            "    .set at\n")
#endif
#ifndef INCLUDE_RODATA
#define INCLUDE_RODATA(NAME)                             \
    __asm__(".section .rodata\n"                         \
            "    .include \"" ASM_DIR "/" #NAME ".s\"\n" \
            ".section .text")
#endif

/*
 * The macro set resolves through the assembler include path, `-I include/match`.
 * Keep these paths relative so a checkout moves.
 */
#if INCLUDE_ASM_USE_MACRO_INC
#else
#endif

#else

#ifndef INCLUDE_ASM
#define INCLUDE_ASM(NAME)
#endif
#ifndef INCLUDE_RODATA
#define INCLUDE_RODATA(NAME)
#endif

#endif /* !defined(M2CTX) && !defined(PERMUTER) */

#endif /* INCLUDE_ASM_H */
