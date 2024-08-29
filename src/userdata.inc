                org 0x5c00
Userdata_template:

T00             db 0x20
T01             db 0x1f
T02             db 0x01
T03             db 0x00
T04             db 0x01
T05             db 0x00
Tjoy_flag       db 0x01 ; joy_flag_002
T07             db 0x00
T08             db 0x01
T09             db 0x00
Tpause          db 0x00
T0b             db 0x05
T0c             db 0x00
T0d             db 0x01
Teither_3210    db 0x00
T0f             db 0x00
T10             db 0x00
T11             db 0x00
T12             db 0x00
T13             db 0x00
T14             db 0x00

Tscore_text
                db 0, 0, 0x07, 0x47

Tscore          db "00000000"
                db 7
Tlives          db "05"
                db 0

Tbottom_text
                db 0xb8, 0x12
                db 0xff, 0xff
                db "EXTRA"
                db 0x85 ; empty
                db 0x5b ; hand start
                db 0x5c ; hand end
                db 0x86 ; empty
                db "BONUS"
                db 0


                org 0x6642
                ; initially filled with random stuff from intro tiles
Userdata:
U00             equ 0x6642
U01             equ 0x6643
U02             equ 0x6644
U03             equ 0x6645 ; perhaps fire duration
U04             equ 0x6646
U05             equ 0x6647
Ujoy_flag       equ 0x6648
U07             equ 0x6649
U08             equ 0x664a
U09             equ 0x664b
Upause          equ 0x664c
U0b             equ 0x664d
U0c             equ 0x664e
U0d             equ 0x664f
Ueither_3210    equ 0x6650 ; perhaps hit mode (depending on U03, fire duration)
U0f             equ 0x6651
U10             equ 0x6652
U11             equ 0x6653
U12             equ 0x6654
U13             equ 0x6655
U14             equ 0x6656
Uscore_text     equ 0x6657
                ; ...
Uscore          equ 0x665b
Ulives          equ 0x6664
Ubottom_text    equ 0x6667
