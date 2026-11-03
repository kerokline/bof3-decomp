/* func_801642F4 - handwritten original (assembly-match, Main-approved).
 * handwritten stream decoder. C89 cannot express the entry-live registers, the $t0
 * context base 0x800327A0, or the computed-jump dispatch; the body
 * is included verbatim from the original image (0x1e4 bytes).
 */
.globl func_801642F4
.type func_801642F4, @function
func_801642F4:
    /* CE2F4 801642F4 21808002 */  addu       $s0, $s4, $zero
  .L801642F8:
    /* CE2F8 801642F8 21600002 */  addu       $t4, $s0, $zero
    /* CE2FC 801642FC 23709201 */  subu       $t6, $t4, $s2
    /* CE300 80164300 0300C005 */  bltz       $t6, .L80164310
    /* CE304 80164304 23704C02 */   subu      $t6, $s2, $t4
    /* CE308 80164308 00000E24 */  addiu      $t6, $zero, 0x0
    /* CE30C 8016430C 00004C26 */  addiu      $t4, $s2, 0x0
  .L80164310:
    /* CE310 80164310 C0780E00 */  sll        $t7, $t6, 3
    /* CE314 80164314 80680E00 */  sll        $t5, $t6, 2
    /* CE318 80164318 2178ED01 */  addu       $t7, $t7, $t5
    /* CE31C 8016431C 21786F02 */  addu       $t7, $s3, $t7
    /* CE320 80164320 23A8AE02 */  subu       $s5, $s5, $t6
    /* CE324 80164324 0800E001 */  jr         $t7
    /* CE328 80164328 23586E01 */   subu      $t3, $t3, $t6
    /* CE32C 8016432C 0000AD92 */  lbu        $t5, 0x0($s5)
    /* CE330 80164330 00000000 */  nop
    /* CE334 80164334 00006DA1 */  sb         $t5, 0x0($t3)
    /* CE338 80164338 0100AD92 */  lbu        $t5, 0x1($s5)
    /* CE33C 8016433C 00000000 */  nop
    /* CE340 80164340 01006DA1 */  sb         $t5, 0x1($t3)
    /* CE344 80164344 0200AD92 */  lbu        $t5, 0x2($s5)
    /* CE348 80164348 00000000 */  nop
    /* CE34C 8016434C 02006DA1 */  sb         $t5, 0x2($t3)
    /* CE350 80164350 0300AD92 */  lbu        $t5, 0x3($s5)
    /* CE354 80164354 00000000 */  nop
    /* CE358 80164358 03006DA1 */  sb         $t5, 0x3($t3)
    /* CE35C 8016435C 0400AD92 */  lbu        $t5, 0x4($s5)
    /* CE360 80164360 00000000 */  nop
    /* CE364 80164364 04006DA1 */  sb         $t5, 0x4($t3)
    /* CE368 80164368 0500AD92 */  lbu        $t5, 0x5($s5)
    /* CE36C 8016436C 00000000 */  nop
    /* CE370 80164370 05006DA1 */  sb         $t5, 0x5($t3)
    /* CE374 80164374 0600AD92 */  lbu        $t5, 0x6($s5)
    /* CE378 80164378 00000000 */  nop
    /* CE37C 8016437C 06006DA1 */  sb         $t5, 0x6($t3)
    /* CE380 80164380 0700AD92 */  lbu        $t5, 0x7($s5)
    /* CE384 80164384 00000000 */  nop
    /* CE388 80164388 07006DA1 */  sb         $t5, 0x7($t3)
    /* CE38C 8016438C 0800AD92 */  lbu        $t5, 0x8($s5)
    /* CE390 80164390 00000000 */  nop
    /* CE394 80164394 08006DA1 */  sb         $t5, 0x8($t3)
    /* CE398 80164398 0900AD92 */  lbu        $t5, 0x9($s5)
    /* CE39C 8016439C 00000000 */  nop
    /* CE3A0 801643A0 09006DA1 */  sb         $t5, 0x9($t3)
    /* CE3A4 801643A4 0A00AD92 */  lbu        $t5, 0xA($s5)
    /* CE3A8 801643A8 00000000 */  nop
    /* CE3AC 801643AC 0A006DA1 */  sb         $t5, 0xA($t3)
    /* CE3B0 801643B0 0B00AD92 */  lbu        $t5, 0xB($s5)
    /* CE3B4 801643B4 00000000 */  nop
    /* CE3B8 801643B8 0B006DA1 */  sb         $t5, 0xB($t3)
    /* CE3BC 801643BC 0C00AD92 */  lbu        $t5, 0xC($s5)
    /* CE3C0 801643C0 00000000 */  nop
    /* CE3C4 801643C4 0C006DA1 */  sb         $t5, 0xC($t3)
    /* CE3C8 801643C8 0D00AD92 */  lbu        $t5, 0xD($s5)
    /* CE3CC 801643CC 00000000 */  nop
    /* CE3D0 801643D0 0D006DA1 */  sb         $t5, 0xD($t3)
    /* CE3D4 801643D4 0E00AD92 */  lbu        $t5, 0xE($s5)
    /* CE3D8 801643D8 00000000 */  nop
    /* CE3DC 801643DC 0E006DA1 */  sb         $t5, 0xE($t3)
    /* CE3E0 801643E0 0F00AD92 */  lbu        $t5, 0xF($s5)
    /* CE3E4 801643E4 00000000 */  nop
    /* CE3E8 801643E8 0F006DA1 */  sb         $t5, 0xF($t3)
    /* CE3EC 801643EC 1000AD92 */  lbu        $t5, 0x10($s5)
    /* CE3F0 801643F0 00000000 */  nop
    /* CE3F4 801643F4 10006DA1 */  sb         $t5, 0x10($t3)
    /* CE3F8 801643F8 1100AD92 */  lbu        $t5, 0x11($s5)
    /* CE3FC 801643FC 00000000 */  nop
    /* CE400 80164400 11006DA1 */  sb         $t5, 0x11($t3)
    /* CE404 80164404 1200AD92 */  lbu        $t5, 0x12($s5)
    /* CE408 80164408 00000000 */  nop
    /* CE40C 8016440C 12006DA1 */  sb         $t5, 0x12($t3)
    /* CE410 80164410 1300AD92 */  lbu        $t5, 0x13($s5)
    /* CE414 80164414 00000000 */  nop
    /* CE418 80164418 13006DA1 */  sb         $t5, 0x13($t3)
    /* CE41C 8016441C 1400AD92 */  lbu        $t5, 0x14($s5)
    /* CE420 80164420 00000000 */  nop
    /* CE424 80164424 14006DA1 */  sb         $t5, 0x14($t3)
    /* CE428 80164428 1500AD92 */  lbu        $t5, 0x15($s5)
    /* CE42C 8016442C 00000000 */  nop
    /* CE430 80164430 15006DA1 */  sb         $t5, 0x15($t3)
    /* CE434 80164434 1600AD92 */  lbu        $t5, 0x16($s5)
    /* CE438 80164438 00000000 */  nop
    /* CE43C 8016443C 16006DA1 */  sb         $t5, 0x16($t3)
    /* CE440 80164440 1700AD92 */  lbu        $t5, 0x17($s5)
    /* CE444 80164444 00000000 */  nop
    /* CE448 80164448 17006DA1 */  sb         $t5, 0x17($t3)
    /* CE44C 8016444C 1800AD92 */  lbu        $t5, 0x18($s5)
    /* CE450 80164450 00000000 */  nop
    /* CE454 80164454 18006DA1 */  sb         $t5, 0x18($t3)
    /* CE458 80164458 1900AD92 */  lbu        $t5, 0x19($s5)
    /* CE45C 8016445C 00000000 */  nop
    /* CE460 80164460 19006DA1 */  sb         $t5, 0x19($t3)
    /* CE464 80164464 1A00AD92 */  lbu        $t5, 0x1A($s5)
    /* CE468 80164468 00000000 */  nop
    /* CE46C 8016446C 1A006DA1 */  sb         $t5, 0x1A($t3)
    /* CE470 80164470 1B00AD92 */  lbu        $t5, 0x1B($s5)
    /* CE474 80164474 00000000 */  nop
    /* CE478 80164478 1B006DA1 */  sb         $t5, 0x1B($t3)
    /* CE47C 8016447C 1C00AD92 */  lbu        $t5, 0x1C($s5)
    /* CE480 80164480 00000000 */  nop
    /* CE484 80164484 1C006DA1 */  sb         $t5, 0x1C($t3)
    /* CE488 80164488 1D00AD92 */  lbu        $t5, 0x1D($s5)
    /* CE48C 8016448C 00000000 */  nop
    /* CE490 80164490 1D006DA1 */  sb         $t5, 0x1D($t3)
    /* CE494 80164494 1E00AD92 */  lbu        $t5, 0x1E($s5)
    /* CE498 80164498 00000000 */  nop
    /* CE49C 8016449C 1E006DA1 */  sb         $t5, 0x1E($t3)
    /* CE4A0 801644A0 1F00AD92 */  lbu        $t5, 0x1F($s5)
    /* CE4A4 801644A4 00000000 */  nop
    /* CE4A8 801644A8 1F006DA1 */  sb         $t5, 0x1F($t3)
    /* CE4AC 801644AC 21A8AE02 */  addu       $s5, $s5, $t6
    /* CE4B0 801644B0 21A8AC02 */  addu       $s5, $s5, $t4
    /* CE4B4 801644B4 21586C01 */  addu       $t3, $t3, $t4
    /* CE4B8 801644B8 23800C02 */  subu       $s0, $s0, $t4
    /* CE4BC 801644BC 8EFF0016 */  bnez       $s0, .L801642F8
    /* CE4C0 801644C0 21586E01 */   addu      $t3, $t3, $t6
    /* CE4C4 801644C4 0800E003 */  jr         $ra
    /* CE4C8 801644C8 00000000 */   nop


func_801644CC:
    /* CE4CC 801644CC 8D010100 */  break      1, 6
    /* CE4D0 801644D0 0800E003 */  jr         $ra
    /* CE4D4 801644D4 00000000 */   nop
.size func_801642F4, . - func_801642F4
