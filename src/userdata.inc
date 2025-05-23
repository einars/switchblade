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
T07_printed     db 0x01
T09             db 0x00
Tpause          db 0x00
T0b             db 0x05
Tsword_parts    db 0x00
Tsword_parts_printed db 0x01
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
Uenergy         equ 0x6642
Uenergy_printed equ 0x6643
U02             equ 0x6644
Uhit_power       equ 0x6645 ; fire duration
Uhit_power_printed equ 0x6646
U05             equ 0x6647
Ujoy_flag       equ 0x6648
Umaybe_is_alive equ 0x6649 ; perhaps is_alive?
U07_printed     equ 0x664a
U09             equ 0x664b
Upause          equ 0x664c
U0b             equ 0x664d
Usword_parts    equ 0x664e ; N of sword parts found
Usword_parts_printed equ 0x664f
Ueither_3210    equ 0x6650 ; perhaps hit mode (depending on U03, fire duration)
U0f             equ 0x6651
U10             equ 0x6652
Uscore_bcd      equ 0x6653 ; 4 bytes
Uscore_text     equ 0x6657 ; printable text starts here — 4 bytes print header
                ; db 0, 0, 7, 0x47
Uscore_ascii    equ 0x665b
                ; db ?,?,?,?,?,?,?,?, 8 bytes ASCII
Uscore_endptr   equ Uscore_ascii + 8
                ; db 7 — tab
Ulives_ascii    equ 0x6664
                ; db ?, ?
                ; db 0 — finish
Ubottom_text    equ 0x6667
