/* func_801642CC - handwritten original (assembly-match, Main-approved).
 * handwritten dispatcher restore tail. C89 cannot express the entry-live registers, the $t0
 * context base 0x800327A0, or the computed-jump dispatch; the body
 * is included verbatim from the original image (0x28 bytes).
 */
.globl func_801642CC
.type func_801642CC, @function
func_801642CC:
    /* CE2CC 801642CC 2400118D */  lw         $s1, 0x24($t0)


func_801642D0:
    /* CE2D0 801642D0 21781600 */  addu       $t7, $zero, $s6
    /* CE2D4 801642D4 2000108D */  lw         $s0, 0x20($t0)
    /* CE2D8 801642D8 2800128D */  lw         $s2, 0x28($t0)
    /* CE2DC 801642DC 2C00138D */  lw         $s3, 0x2C($t0)
    /* CE2E0 801642E0 3000148D */  lw         $s4, 0x30($t0)
    /* CE2E4 801642E4 3400158D */  lw         $s5, 0x34($t0)
    /* CE2E8 801642E8 3800168D */  lw         $s6, 0x38($t0)
    /* CE2EC 801642EC 0800E003 */  jr         $ra
    /* CE2F0 801642F0 3C00178D */   lw        $s7, 0x3C($t0)
.size func_801642CC, . - func_801642CC
