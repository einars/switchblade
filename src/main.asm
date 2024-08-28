                device zxspectrum48

                org 0x4010

                include "labels.inc"

Buffer equ 0x5b00


Start:
                ld sp, 0x5c00
                xor a
                out (0xfe), a
                ld a, 0xfe
                ld i, a 
                im 2
                jp 0x5cfa


                org 0x5c00
                db 0x20, 0x1f, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00,   0x01, 0x00, 0x00, 0x05, 0x00, 0x01, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,   0x47, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30
                db 0x30, 0x07, 0x30, 0x35, 0x00, 0xb8, 0x12, 0xff,   0xff, 0x45, 0x58, 0x54, 0x52, 0x41, 0x85, 0x5b
                db 0x5c, 0x86, 0x42, 0x4f, 0x4e, 0x55, 0x53, 0x00,   0x42, 0x42, 0x42, 0x42, 0x42, 0x47, 0x47, 0x47
                db 0x47, 0x47, 0xcd, 0x1a, 0x83, 0x3e, 0xff, 0xcd,   0xc0, 0x5f, 0xcd, 0x06, 0xa8, 0x3e, 0x80, 0xcd
                db 0xc0, 0x5f, 0xcd, 0x3e, 0xa7, 0x21, 0x26, 0x81,   0x01, 0x0a, 0x0a, 0xc5, 0xcd, 0x68, 0x5c, 0x09
                db 0x0e, 0x0b, 0x09, 0xc1, 0x10, 0xf5, 0x18, 0x2b,   0x11, 0x13, 0x82, 0x06, 0x00, 0x13, 0x1a, 0xed
                db 0xa1, 0xc0, 0xaf, 0xb1, 0x20, 0xf7, 0x01, 0xfe,   0xf7, 0xed, 0x78, 0x1f, 0x01, 0x06, 0x0d, 0x30
                db 0x15, 0x1f, 0x01, 0x09, 0x12, 0x30, 0x0f, 0x1f,   0x01, 0x0f, 0x0e, 0x30, 0x09, 0x1f, 0x01, 0x0f
                db 0x14, 0x30, 0x03, 0x01, 0x00, 0x03, 0xed, 0x43,   0xdf, 0x69, 0x00, 0x00, 0x00, 0x21, 0x00, 0x6d
                db 0x75, 0x11, 0x01, 0x6d, 0x01, 0xff, 0x01, 0xed,   0xb0, 0x21, 0x00, 0x5c, 0x11, 0x42, 0x66, 0x01
                db 0x38, 0x00, 0xed, 0xb0, 0x21, 0xd8, 0x76, 0x06,   0x06, 0x36, 0x01, 0x23, 0x10, 0xfb, 0x21, 0x00
                db 0x5d, 0x01, 0x04, 0x48, 0x11, 0xca, 0x65, 0x3e,   0x24, 0xcd, 0x5d, 0xa6, 0x3e, 0x07, 0x32, 0x02
                db 0x5d, 0xaf, 0x32, 0xae, 0x88, 0xcd, 0x39, 0x83,   0x3e, 0x02, 0x32, 0x52, 0x84, 0xfd, 0x21, 0x00
                db 0x5d, 0xcd, 0xc3, 0x95, 0xcd, 0x65, 0x83, 0xcd,   0xeb, 0xff, 0x3e, 0x46, 0x28, 0x02, 0x3e, 0x07
                db 0xcd, 0x5a, 0x83, 0xaf, 0x32, 0x5f, 0x84, 0xc3,   0xfe, 0x8d

Entry:          call Joystuff
                call Intro_movie

                ;org 0x5d00
                db 0x3e, 0x0a, 0x21, 0x5c, 0x6b, 0x16, 0x5d, 0x01,   0x7e, 0x00, 0x1e, 0x82, 0xed, 0xb0, 0x3d, 0x20
                db 0xf6, 0x21, 0x00, 0x6f, 0xf5, 0x5f, 0xcb, 0x13,   0xb3, 0x5f, 0xcb, 0x1b, 0xb3, 0x2f, 0x77, 0x23
                db 0xf1, 0x3c, 0x20, 0xf0, 0x06, 0x0c, 0x77, 0x2c,   0xc6, 0x14, 0x10, 0xfa, 0x0e, 0x05, 0x11, 0x34
                db 0x0e, 0x06, 0x06, 0xd5, 0x3e, 0x04, 0x82, 0x57,   0x73, 0x2c, 0x72, 0x2c, 0x10, 0xf6, 0xd1, 0x3e
                db 0x10, 0x83, 0x5f, 0x0d, 0x20, 0xeb, 0x01, 0xdc,   0x24, 0xcd, 0xef, 0x70, 0xc3, 0x4d, 0x5c

Intro_movie:
                ld a, 7
                call Clear_screen
                ld iy, Intro.Frame_00
                ld de, 0x3090 ; coords
                ld bc, 0x805 ; box 5x8
                call Draw_box_and_everything ; and wait a bit for fire
                call Print_iy ; "now he has awakened"
                call Draw_just_sprite ; and wait a miniscule amount: eye opening frame 1
                call Draw_just_sprite ; and wait a miniscule amount: eye opening frame 2

                ld a, 0x42     ; color.red + bg.black + bright
                ld (0x5a9c), a ; red eye glows
                call Draw_just_sprite ; eye opening frame 3
                call Wait_fire_some_time

                ld a, 7
                call Clear_screen

                ld hl, Intro.Attr_sword_shiny
                ld de, 0x5882 ; somewhere on screen
                ld bc, 0x0503  ; 5x3 area
                call Blit_square_attributes

                ld de, 0x0008
                ld bc, 0x0713
                call Draw_box_and_everything ; shiny sword

                ld a, 7
                out (0xfe), a

                ld hl, Intro.Attr_sword_shattered
                ld de, 0x5882
                ld bc, 0x503
                call Blit_square_attributes

                ld bc, 0x2000
                call Delay_custom

                ld a, 0
                out (0xfe), a

                call Draw_sprite_and_text ; no border. sword shattered

                ld a, 7
                call Clear_screen

                ld hl, Intro.Attr_Hiro
                ld de, 0x5828
                ld bc, 0x0d10
                call Blit_square_attributes

                ; Hiro
                ld de, 0x0f00
                ld bc, 0x120f
                call Draw_box_and_everything ; hiro + "they newer thought he would return"

                call Draw_just_text ; I am hiro, the last of the bladeknights

                ld h, 0x3c
                call Wait_fire_custom

                jp nz, Intro_movie
                ret





Draw_box_and_everything:
                call DrawBox
Draw_sprite_and_text:
                call Print_iy_with_alt_tileset
Draw_just_text:
                call Print_iy
                jp Wait_fire_some_time

Draw_just_sprite:
                call Print_iy_with_alt_tileset
                ld h, 1
                jp Wait_fire_custom

Print_iy_with_alt_tileset:
                push iy
                pop hl
                ld bc, Intro.Tiles
                call Print_something_custom
                jr 1f

Print_iy:       push iy
                pop hl
                call Print.String_alt
1               push hl
                pop iy
                ret


DrawBox:
                ; DE = coords
                ; A = attrib
                ; C = width
                ; B = height
                ld (Buffer + 1), de ; coords
box_attrs+*     ld a, 6 ;sic: smc!
                ld (Buffer + 3), a ; attrs
                ld (Buffer + 4), a ; attrs

                ld hl, Buffer + 5
                push bc
                ld e, 0x22 ; ╔
                ld d, 0x24 ; ╗
                ld a, 0x23 ; ═
                call Box_top_btm
                ld (hl), 0xff
                inc hl
                pop bc
                dec c
                dec c

1               push bc
                call Box_sides
                pop bc
                dec c
                jr nz, 1b

                ld e, 39
                ld d, 41
                ld a, 40

                call Box_top_btm
                ld (hl), 0
                ld hl, Buffer + 1
                call Print.String_alt
                ret


Box_top_btm:
                dec b
                dec b
                ld (hl), e
                inc hl
1               ld (hl), a
                inc hl
                djnz 1b
                ld (hl), d
                inc hl
                ret

Box_sides:
                dec b
                dec b
                ld (hl), 0x25 ; ║
                inc hl
                ld (hl), b    ; advance B bytes (chr < 0x20)
                inc hl
                ld (hl), 0x25 ; ║
                inc hl
                ld (hl), 0xff
                inc hl
                ret

; intro.Sprites/texts are here, 0x5e4d..0x61e4
; ...

                org 0x61e5

Print_something_custom:
                push bc
                ld b, (hl)
                inc hl
                ld c, (hl)
                push hl
                call Print.Screen_addr ; de = addr
                pop hl
                pop bc
                inc hl

1               ld a, (hl)
                inc hl
                or a
                ret z

                push bc
                push hl
                inc a
                jr z, 3f
                dec a
                dec a
                ld h, 0
                ld l, a
                add hl, hl
                add hl, hl
                add hl, hl
                add hl, bc ; (a - 1) * 8 + BC
                call Print.Char
2               pop hl
                pop bc
                jr 1b

3               ld bc, (Print.String_alt.next_line_coord)
                call Print.Screen_addr
                jr 2b

Blit_square_attributes:
                ; blit attribute map, b x c bytes
                ; hl = buffer
                ; de = screen target
1               push bc
                push de
                ld b, 0
                ldir
                pop de
                ld a, 32
                add a, e
                ld e, a
                ld a, 0
                adc a, d
                ld d, a
                pop bc
                djnz 1b
                ret



                org 0x6225 + 15 + 15

                ; intro tiles come here, 0x6313..0x6a03
                include "intro.inc"

                assert ($ = 0x6a7b)
Joystuff:
; print the joystick menu, wait for input and patch-up the joystick routines

                xor a
                call Clear_screen
                ld hl, txt_joy
                call Print.Text

                ld de, 14
2               ld a, 0xf7
                in a, (0xfe)
                ld hl, joy_flags
                ld b, 4

1               rra
                jr nc, Joystuff_cont
                add hl, de
                djnz 1b
                jr 2b
Joystuff_cont
                ld a, (hl)
                inc hl
                ld (Ljoy_flag_001), a 
                ld (Ljoy_flag_002), a 
                ld a, (hl)
                ld (joy_flag_3a), a
                ld (joy_flag_3b), a
                inc hl
                ld a, (hl)
                ld (joy_flag_4), a
                inc hl
                ld a, (hl)
                ld (joy_flag_5), a
                inc hl
                ld a, (hl)
                ld (joy_flag_6), a
                inc hl
                ld a, (hl)
                ld (joy_flag_7), a
                inc hl
                ld a, (hl)
                ld (joy_flag_8), a
                inc hl
                ld de, Joystick_read
                ld bc, 18 ; install small, dev-specific Joystick_read routine
                ldir
                ret

txt_joy
                db 0x34, 0x0e, 0x07, 0x47 ; coords-x, coords-y, attrs-bottom-line, attrs-top-line
                db "1.JOYSTICK 1"
                db 0xff, 0xff
                db "2.JOYSTICK 2"
                db 0xff, 0xff
                db "3.KEMPSTON"
                db 0xff, 0xff
                db "4.PROTEK OR CURSOR"
                db 0

joy_flags
                ; joystick 1
                db 0x01, 0x1e : rra : dec e : inc e : inc d : dec d
                ld a, 0xef : in a, (0xfe) : bit 0, a : ret ; routine, pushed into Joystick_read

                ; joystick 2
                db 0x10, 0x0f : nop : dec d : inc d : inc e : dec e
                ld a, 0xf7 : in a, (0xfe) : bit 4, a : ret ; routine, pushed into Joystick_read

                ; joystick 3
                db 0x10, 0x0f : nop : inc d : dec d : inc e : dec e
                in a, (0x1f) : cpl : bit 4, a : ret : nop

                ; joystick 4
                db 0x01, 0x1e : rra : dec d : inc d : dec e : inc e
                ld a, 0xf7 : in a, (0xfe) : or 0xef : rrca : rrca : rrca : ld c, a
                ld a, 0xef : in a, (0xfe) : and c   : bit 0, a : ret

                include "wip.asm"

	savesna "switchblade.sna", Start
