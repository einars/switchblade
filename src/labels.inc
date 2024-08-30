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

; vars in mach-zone
L69e3 equ 0x69e3 ; machC[e3]
L69df equ 0x69df ; machC[df]

smc_L9ba3 equ 0x9ba3

Pre_game_color_modes equ 0x66fa ; V

smc_L845f equ int_enable

VQ5fc0 equ 0x5fc0

smc_L88ae equ 0x88ae
smc_L878f equ 0x878f

; abstract addresses, not matching actual source
L5fee equ 0x5fee ; V
L5ff7 equ 0x5ff7 ; V

Xif_something_1a equ 0x65ee ; V
X65ee equ Xif_something_1a

L80eb equ 0x80eb

X5fcb equ 0x5fcb ; V, marked
L6bdd equ 0x6bdd ; V
L65ed equ 0x65ed ; V
L65dc equ 0x65dc ; V
L69dd equ 0x69dd ; V
L5c45 equ 0x5c45 ; V
X6682 equ 0x6682 ; V
X66b6 equ 0x66b6 ; V

L7afb equ 0x7afb

L898c equ 0x898c

X8a73 equ 0x8a73

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

