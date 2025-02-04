;Buffer_yy       equ 0x6d00
                ; 6d00..6eff
                ; some other buffer
;Mask_table      equ 0x6f00 ; generated 256 bytes mapping of byte -> mask = ~(orig | ( orig << 1) | (orig >> 1))
;Mult20_table    equ 0x7000 ; 12 bytes of x mult 20
                ; db 00, 14, 28, 3c, 50, 64, 78, 8c, a0, b4, c8, dc
;X01_table       equ 0x700c ; 5 rows of 6 elements of some addresses? offsets?
                ; dw 1234, 1634, 1a34, 1e34, 2234, 2634



; magic_vars im2_always
; L8557 equ mv1
; L8558 equ mv2
; L8559 equ mv3
; L855a equ mv4

BR equ 0xff

mach0 equ 0x5d00
mach1 equ 0x5e00
mach2 equ 0x5f00
mach3 equ 0x6000
mach4 equ 0x6100
mach5 equ 0x6200
mach6 equ 0x6300
mach7 equ 0x6400
mach8 equ 0x6500
mach9 equ 0x6600 ; 6642 — userdata
machA equ 0x6700
;
machB equ 0x6800
machC equ 0x6900
machD equ 0x6a00
machE equ 0x6b00
machF equ 0x6c00

L8683 equ 0x8683 ; some 12-byte table?

Data_zfz equ 0x6082 ; V, marked

; vars in mach-zone, outside of some-initial-buffers
L68db equ 0x68db ; some buffer written to by 8a90
L69e3 equ 0x69e3
L69dd equ 0x69dd
L69de equ 0x69de
L69df equ 0x69df
L6bdd equ 0x6bdd
L5d42 equ 0x5d42
L5d01 equ 0x5d01
L5d1b equ 0x5d1b
L5d4a equ 0x5d4a
L6640 equ 0x6640


; used in Pipelogo, afterwards reset w/automasks
L6f08 equ 0x6f08

smc_L9ba3 equ 0x9ba3

Pre_game_color_modes equ 0x66fa ; V

VQ5fc0 equ 0x5fc0
VQ5fee equ 0x5fee

smc_L88ae equ 0x88ae
smc_L878f equ 0x878f


Vreset_attrs_8_bottoms equ 0x65ee ; V

; v-overrides with correct addreses 
; (in code they are marked as .private labels)
VQ5fcb equ 0x5fcb
VL65ca equ 0x65ca
VL65dc equ 0x65dc
VL65a6 equ 0x65a6
VQ66c8 equ 0x66c8 
VQ66bd equ 0x66bd
VQ66b6 equ 0x66b6
VQ6682 equ 0x6682
VL69e2 equ 0x69e2
VL6bdd equ 0x6bdd

X9a4b equ X9a27.e_9a4b
X9a89 equ X9a27.e_9a89

X97a3 equ Set_bit5_of_10h

; -- 

L79ff equ 0x79ff ; modified when extra or bonus full?

Xa652 equ 0xa652

Xa569 equ 0xa569
X8855 equ 0x8855
La59e equ 0xa59e
Xa58a equ 0xa58a
X9ba2 equ 0x9ba2

J872b equ 0x872b
J9087 equ 0x9087

smc_L7b63 equ 0x7b63

;smc_L8b15 equ Q8a90.param_1 ; 0x8b15
;smc_L8b61 equ Q8a90.param_de ; 0x8b61
;smc_L8c76 equ Drawing_routine.pipe_b_param

smc_L8b6b equ 0x8b6b
smc_L8c1e equ 0x8c1e
smc_L9a59 equ 0x9a59
smc_La56e equ 0xa56e
smc_La56f equ 0xa56f
smc_L9be9 equ 0x9be9

Xa59b equ 0xa59b
X8edd equ 0x8edd
X98f3 equ 0x98f3

X965f equ 0x965f
L651e equ 0x651e
Xa65d equ 0xa65d

L9cd9 equ 0x9cd9
L904a equ 0x904a
L9163 equ 0x9163
L90a6 equ 0x90a6
L926e equ 0x926e

; smc_L8b86 equ X8b6a.param_e
; smc_L8b87 equ X8b6a.param_d
; smc_L8b88 equ X8b6a.param_c

; smc_L8c1e equ X8c0a.param_pos
; smc_L8c13 equ X8c0a.n_lines

; X8bc5 equ Weird_blit
; X8bc8 equ Weird_blit.entry_de

X9ca7 equ 0x9ca7
L906c equ 0x906c
L9225 equ 0x9225
L91b8 equ 0x91b8
Xa6b1 equ 0xa6b1

L9b53 equ 0x9b53 ; next
