;Buffer_yy       equ 0x6d00
                ; 6d00..6eff
                ; some other buffer
;Mask_table      equ 0x6f00 ; generated 256 bytes mapping of byte -> mask = ~(orig | ( orig << 1) | (orig >> 1))
;Mult20_table    equ 0x7000 ; 12 bytes of x mult 20
                ; db 00, 14, 28, 3c, 50, 64, 78, 8c, a0, b4, c8, dc
;X01_table       equ 0x700c ; 5 rows of 6 elements of some addresses? offsets?
                ; dw 1234, 1634, 1a34, 1e34, 2234, 2634



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

Data_zfz equ 0x6082 ; V, marked

; vars in mach-zone, outside of some-initial-buffers
L69e3 equ 0x69e3
L69dd equ 0x69dd
L69de equ 0x69de
L69df equ 0x69df
L6bdd equ 0x6bdd
L6652 equ 0x6652
L5d42 equ 0x5d42
L5d4a equ 0x5d4a
L6640 equ 0x6640
L664c equ 0x664c

smc_L9ba3 equ 0x9ba3

Pre_game_color_modes equ 0x66fa ; V

smc_L845f equ int_enable

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

L898c equ 0x898c

Xa65d equ 0xa65d
X8a73 equ 0x8a73
X8333 equ 0x8333
X97a3 equ 0x97a3

Xff01 equ 0xff01
Xff64 equ 0xff64

L79ff equ 0x79ff

L7600 equ Logo_ani_pt1

L8943 equ 0x8943

X8f3b equ 0x8f3b
La6ec equ 0xa6ec

smc_L8c76 equ 0x8c76
smc_L8d27 equ 0x8d27
X8a79 equ 0x8a79
X8c68 equ 0x8c68

X8f75 equ 0x8f75
Xa569 equ 0xa569
X8855 equ 0x8855
La59e equ 0xa59e
Xa58a equ 0xa58a
X9ba2 equ 0x9ba2

X8907 equ 0x8907
X9a4b equ 0x9a4b
X8e98 equ 0x8e98
X8a76 equ 0x8a76

J872b equ 0x872b

smc_L9a59 equ 0x9a59

Xa806 equ 0xa806
X8fdd equ 0x8fdd
X9000 equ 0x9000

smc_L7b63 equ 0x7b63
smc_La56e equ 0xa56e
smc_L89f6 equ 0x89f6

X898c equ 0x898c

J8330 equ 0x8330
