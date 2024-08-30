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



; unprocessed labels
X6a7b equ 0x6a7b
Ljoy_flag_002 equ 0x5c06 ; sic

L6667 equ 0x6667

X831f equ Wait_fire_some_time
X8321 equ Wait_fire_custom
X61e5 equ Print_something_custom

X8330 equ Delay
X8333 equ Delay_custom

; im2
X853f equ 0x853f

X8e77 equ 0x8e77


;smc_L865b equ beep_dur0
;smc_L865d equ beep_dur1

; magic_vars im2_always
L8557 equ mv1
L8558 equ mv2
L8559 equ mv3
L855a equ mv4

L8683 equ 0x8683 ; some 12-byte table?

L8454 equ maybe_sound_to_play

;L8454_is_ff equ 0x8634

L6602 equ 0x6602

L69e3 equ 0x69e3

smc_L9ba3 equ 0x9ba3

X70ef equ 0x70ef

Pre_game_color_modes equ 0x66fa ; V
L66fa equ Pre_game_color_modes ; V

smc_L845f equ int_enable

; variables from after-table initializer:
L69df equ 0x69df
L5d02 equ 0x5d02
L8452 equ 0x8452
L8dfe equ 0x8dfe

X5fc0 equ 0x5fc0
Xa65d equ 0xa65d
X95c3 equ 0x95c3
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

X9b71 equ 0x9b71
X8f3b equ 0x8f3b
La6ec equ 0xa6ec

smc_L8c76 equ 0x8c76
smc_L8d27 equ 0x8d27
X8a79 equ 0x8a79
X8c68 equ 0x8c68

