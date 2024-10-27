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

X97a3 equ Set_bit5_of_10h

; -- 

L79ff equ 0x79ff ; modified when extra or bonus full?

La6ec equ 0xa6ec

X9a27 equ 0x9a27
X8e95 equ 0x8e95
Xa652 equ 0xa652

Xa569 equ 0xa569
X8855 equ 0x8855
La59e equ 0xa59e
Xa58a equ 0xa58a
X9ba2 equ 0x9ba2

X9a4b equ 0x9a4b
X8e98 equ 0x8e98

J872b equ 0x872b

smc_L7b63 equ 0x7b63

;smc_L8b15 equ Q8a90.param_1 ; 0x8b15
;smc_L8b61 equ Q8a90.param_de ; 0x8b61
;smc_L8c76 equ Drawing_routine.pipe_b_param

smc_L8b6b equ 0x8b6b
smc_L8c13 equ 0x8c13
smc_L8c1e equ 0x8c1e
smc_L9a59 equ 0x9a59
smc_La56e equ 0xa56e
smc_La56f equ 0xa56f

; X8b6a:
smc_L8b85 equ 0x8b85 ; 5d + column
smc_L8b86 equ 0x8b86 ; 5d + column
smc_L8b88 equ 0x8b88 ; 5d + column


Xa806 equ 0xa806

X8c0a equ 0x8c0a
X8bc8 equ 0x8bc8
X8ea3 equ 0x8ea3

Xa59b equ 0xa59b
X8edd equ 0x8edd
X8b6a equ 0x8b6a
X8c51 equ 0x8c51
X98f3 equ 0x98f3

X965f equ 0x965f
L651e equ 0x651e
Xa65d equ 0xa65d
