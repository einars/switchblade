;Buffer_xx       equ 0x6700
                ; 6700 .. 6cff
                ; some 6x256 visual buffer?
;Buffer_yy       equ 0x6d00
                ; 6d00..6eff
                ; some other buffer
;Mask_table      equ 0x6f00 ; generated 256 bytes mapping of byte -> mask = ~(orig | ( orig << 1) | (orig >> 1))
;Mult20_table    equ 0x7000 ; 12 bytes of x mult 20
                ; db 00, 14, 28, 3c, 50, 64, 78, 8c, a0, b4, c8, dc
;X01_table       equ 0x700c ; 5 rows of 6 elements of some addresses? offsets?
                ; dw 1234, 1634, 1a34, 1e34, 2234, 2634



X831f equ Wait_fire_some_time
X8321 equ Wait_fire_custom
X61e5 equ Print_something_custom

X8330 equ Delay
X8333 equ Delay_custom

;smc_L865b equ beep_dur0
;smc_L865d equ beep_dur1

; magic_vars im2_always
L8557 equ mv1
L8558 equ mv2
L8559 equ mv3
L855a equ mv4

mach0 equ 0x5d00
mach1 equ 0x5e00
mach2 equ 0x5f00
mach3 equ 0x6000
mach4 equ 0x6100
mach5 equ 0x6200
mach6 equ 0x6300
mach7 equ 0x6400
mach8 equ 0x6500
mach9 equ 0x6600
machA equ 0x6700
;
machB equ 0x6800
machC equ 0x6900
machD equ 0x6a00
machE equ 0x6b00
machF equ 0x6c00

L8683 equ 0x8683 ; some 12-byte table?

L8454 equ maybe_sound_to_play

L69e3 equ 0x69e3

smc_L9ba3 equ 0x9ba3

X70ef equ 0x70ef

Pre_game_color_modes equ 0x66fa ; V
L66fa equ Pre_game_color_modes ; V

smc_L845f equ int_enable

; variables from after-table initializer:
L69df equ 0x69df
L8452 equ 0x8452
L8dfe equ 0x8dfe

X5fc0 equ 0x5fc0
Xffeb equ 0xffeb

smc_L88ae equ 0x88ae
smc_L878f equ 0x878f

; abstract addresses, not matching actual source
L5fee equ 0x5fee ; V
L5ff7 equ 0x5ff7 ; V

Xif_something_1a equ 0x65ee ; V
X65ee equ Xif_something_1a

L7f1d equ 0x7f1d
L80eb equ 0x80eb

L6bdd equ 0x6bdd ; V
L65ed equ 0x65ed ; V
L65dc equ 0x65dc ; V


L7600 equ Logo_ani_pt1

X8f3b equ 0x8f3b
La6ec equ 0xa6ec

smc_L8c76 equ 0x8c76
smc_L8d27 equ 0x8d27
X8a79 equ 0x8a79
X8c68 equ 0x8c68

Xa6d8 equ 0xa6d8
X8f75 equ 0x8f75
X5fcb equ 0x5fcb ; V
Xa569 equ 0xa569
X8855 equ 0x8855
La59e equ 0xa59e
Xa58a equ 0xa58a
X9bb6 equ 0x9bb6
X9ba2 equ 0x9ba2

smc_L9a59 equ 0x9a59

