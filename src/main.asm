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


                include "userdata.inc"
                ; userdata template goes here, 5c00..5c37
                ; real userdata will be stored at


                org 0x5c38
bbbbbggggg:
                ; perhaps EXTRA and BONUS attributes
                db "BBBBB"
ggggg:
                db "GGGGG"

                org 0x5c42
                db 0xcd, 0x1a, 0x83
Q5c45:
                ld a, 0xff
                call VQ5fc0
                
                call Xa806

J5c4d
                ld a, 0x80

                call VQ5fc0

                ; this will alternate between switchblade animation and highscores, and wait for the fire
                call Pre_game_animations
                ; animations finished, fire pressed

                ; the actual game will probably start here
                ld hl, Hiscores + 13 ; 0x8126 hiscores, pointing to first name?
                ld bc, 0x0a0a

1               push bc
                call X5c68
                add hl, bc
                ld c, 11
                add hl, bc
                pop bc
                djnz 1b

                jr L5c93

X5c68:          ld de, 0x8213
                ld b, 0
1               inc de
                ld a, (de)
                cpi
                ret nz
                xor a
                or c
                jr nz, 1b
                ld bc, 0xf7fe
                in a, (c) ; keyboard, 1-2-3-4-5
                rra
                ld bc, 0x0d06
                jr nc, do_stuff
                rra
                ld bc, 0x1209
                jr nc, do_stuff
                rra
                ld bc, 0x0e0f
                jr nc, do_stuff
                rra
                ld bc, 0x140f
                jr nc, do_stuff

L5c93           ld bc, 0x0300

do_stuff:       ld (L69df), bc
                nop
                nop
                nop
                ; clean yy buffer
                ld hl, Buffer_yy
                ld (hl), l
                ld de, Buffer_yy + 1
                ld bc, 0x200 - 1
                ldir

                ld hl, Userdata_template
                ld de, Userdata
                ld bc, 0x38
                ldir

                ld hl, Some_6_bools
                ld b, 6

1               ld (hl), 1
                inc hl
                djnz 1b

                ld hl, 0x5d00
                ld bc, 0x4804
                ld de, 0x65ca
                ld a, 0x24
                call Qa65d

                ld a, 7
                ld (mach0 + 2), a
                xor a
                ld (smc_L88ae), a
                call Clear_screen
                
                ld a, 2
                ld (var_8452), a

                ld iy, 0x5d00
                call X95c3
                call Print.Write_sys_top_bottom
                call Fill_bottom_row_attrs

                ; fill screen with white-on-black, or bright/black-on-cyan?
                ld a, 0x46
                jr z, 2f
                ld a, 7
2               call Clear_some_attrs
                xor a
                ld (int_enable), a
                jp J8dfe





                ; org 0x5cfa
Entry:          call Joystuff
                call Intro_movie

                ; 5d00
                ld a, 10
                ld hl, Some_initial_buffers
                ld d, 0x5d

                ; move to de = 5d82 — start destroying intro movie data as a buffer
                ; 10 buffers of 7e = 126 byte
                ; 6b5c -> 5d82 0x7e bytes
                ; 6bda -> 5e82 0x7e bytes
                ; 6c58 -> 5f82
                ; 6cd6 -> 6082
                ; 6d54 -> 6182
                ; 6dd2 -> 6282
                ; 6e50 -> 6382
                ; 6ece -> 6482
                ; 6f4c -> 6582
                ; 6fca -> 6682

                ; in total 1260 bytes — 6b5c..7048 - 1?

1               ld bc, 0x007e
                ld e, 0x82 
                ldir
                dec a
                jr nz,1b

                ; prepare a 256-byte mask table at 0x6f00
                ; ---#---- -> 
                ; ##---###
                ld hl, Mask_table ; 0x6f00

2               push af
                ld e, a
                rl e
                or e
                ld e, a
                rr e
                or e
                cpl
                ld (hl), a
                inc hl
                pop af
                inc a
                jr nz, 2b

                ld b, 12

                ; 12 bytes 0x7000 — mult-20 - table

3               ld (hl), a
                inc l
                add a, 0x14 ; 20
                djnz 3b

                ;0x700c 30 words
                ; HL = X01_table
                ld c, 5
                ld de, 0x0e34
5               ld b, 6
                push de

4               ld a, 4
                add a, d
                ld d, a
                ld (hl), e
                inc l
                ld (hl), d
                inc l
                djnz 4b

                pop de
                ld a, 16
                add a, e
                ld e, a
                dec c
                jr nz, 5b

                ; 5d46
                ld bc, 0x24dc ; last 36 bytes of each 6-line; 24+dc = 100
                call Clean_square_at_67xx
                jp J5c4d

                ; 5d4f

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

                assert ($ = 0x6225)

                ; intro gfx live here
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
                ld (joy_flag_1), a 
                ld (Tjoy_flag), a ; in userdata template
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
	;savebin "switchblade.bin", 0x5b00, 0xa500
