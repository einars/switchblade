                module Hiscore

                org 0xa806

Hiscore_cursor_pos equ 0x5d00

Screen:
                ld c, 0xbd
                ld hl, first_score_ptr + 8

1               ld b, 8
                ld de, Uscore_ascii + 8
                xor a
                ld (Enter.current_letter), a

2               dec hl
                dec de
                ld a, (de)
3               sbc a, (hl)
                djnz 2b

                jr nc, 4f
                ld de, 0x1d
                add hl, de
                ld a, c
                sub 0x15 ; 21 dec
                ld c, a
                cp 0xeb ; 0xbd - 0x15 x 10 — final score?
                ret z   ; score too small
                jr 1b


4               push hl
                ld a, c
                or a
                jr z, .skip_move ; the last place?

                ; move the remaining scores down
                ld hl, 0x81d9
                ld de, 0x81ee
                lddr

                ; the hiscore will be stored now
.skip_move      ld hl, Uscore_ascii
                pop de
                ld c, 8
                ldir

                inc de
                push de
                ld a, 1
                ld (int_enable), a
                xor a
                call Clear_screen
                call Hiscore.Enter
                ld hl, name_buffer + 10
                ld a, '-' ; 0x2d
                ld b, 10

                ; replace '-' with space for some reason
6               dec hl
                cp (hl)
                jr nz, .skip_space
                ld (hl), 0x20
.skip_space     djnz 6b

                pop de
                ld c, 10 ; and move the name to the place
                ldir
                ret


                assert($ == 0xa861)
Enter:          
                ; clean name buffer
                ld b, 10
                ld hl, name_buffer
.c              ld (hl), '-' : inc hl : djnz .c

                ld hl, 0x0504 ; put cursor at the ED/enter (col 6, row 5)
                ld (Hiscore_cursor_pos), hl
                ld hl, 0x12a0
                ld (txt_maybe_cursor), hl
                ld hl, txt_Well_done
                call Print.Text
                call Print.String_alt ; txt_Well_done_pt_2
                call Print.String_alt ; txt_Well_done_selector

                ld l, 10
.delay          call Delay : dec l : jr nz, .delay

.redraw_name
                ld hl, txt_name_buffer
                call Print.Text
                call Print.String_alt ; txt_maybe_cursor

.joy_loop       call Joystick_read
                jr z, .joy_done

                call Joystick_parse
                call c, Hiscore_advance_and_redraw_cursor
                jr .joy_loop

.joy_done       ld bc, 0x8000
                call Delay_custom

                call Xa91b ; probably get letter at cursor

                cp 0x1a
                jr c, 7f

                ld c, 0x21
                jr z, 8f
                dec c
                cp 0x1b
                jr z, 8f
                cp 0x1c
                ret nz

                ld c, '-'
                ld e, 0xff
                ld d, e
                jr .store_letter

7               add a, 0x41
                ld c, a

8               ld e, 1
                ld d, 10

.store_letter
                ; store char into name_buffer
                ; c = character
                ; e = +1 / -1
                ; d = limit (10 or -1)
.current_letter equ $ + 1
                ld a, 1 ; smc current_letter, reset to 0 by caller
                ld b, a 
                ld hl, name_buffer
                add a, l
                ld l, a
                ld (hl), c

                ld a, b
                add a, e
                cp d ; last letter?
                jr z, .redraw_name

                ; advance cursor
                ld (.current_letter), a
                ld hl, txt_maybe_cursor + 1
                ld a, e
                add a, a
                add a, (hl)
                ld (hl), a
                jr .redraw_name




                assert($ == 0xa8e2)

Hiscore_advance_and_redraw_cursor:
                ; DE: offset
                ;  D — x +1/-1
                ;  E - y +1/-1
                ;  return if out of bounds
                ld hl, Hiscore_cursor_pos
                ld a, e
                add a, (hl)
                ret m
                cp 5
                ret z
                ld e, a
                inc l
                ld a, d
                add a, (hl)
                ret m
                cp 6
                ret z
                ld (hl), a
                dec l
                ld (hl), e

                ld hl, (txt_Well_done_selector)
                ld (txt_square), hl
                ld hl, txt_square
                call Print.String_alt
                call Xa91b

                add a, a
                add a, 12
                ld l, a

                ld h, 0x70
                ;HL = pointer to word[] Hiscore_cursor_positions @ 0x700c
                ld e, (hl)
                inc l
                ld d, (hl)
                ld (txt_Well_done_selector), de
                ld hl, txt_Well_done_selector
                call Print.String_alt
                jp Delay


Xa91b:          
                ld bc, (Hiscore_cursor_pos)
                ld h, c
                ld e, 6
                call mul_h_e
                ld a, b
                add a, l
                ret


Cursor_positions equ 0x700c
                ; 5 rows of 6 elements of screen cursor ptrs
                ; for hiscore entry
                ; dw 1234, 1634, 1a34, 1e34, 2234, 2634
                ; dw 1244, 1644, 1a44, 1e44, 2244, 2644
                ; dw 1254, 1654, 1a54, 1e54, 2254, 2654
                ; dw 1264, 1664, 1a64, 1e64, 2264, 2664
                ; dw 1274, 1674, 1a74, 1e74, 2274, 2674


                ; DATA

                org 0x8119
txt_hiscore_table:
                db 0x14, 0x14, 0x07, 0x47
first_score_ptr equ $
                db "00100400"
                db 4, "JEFF C    ", BR, BR
                db "00094010", 4, "LINDA     ", BR, BR
                db "00089050", 4, "SIMES     ", BR, BR
                db "00087470", 4, "DANGERSTU ", BR, BR
                db "00060360", 4, "GREGGS    ", BR, BR
                db "00060290", 4, "JAMIE     ", BR, BR
                db "00048540", 4, "RAY       ", BR, BR
                db "00033760", 4, "MONTY     ", BR, BR
                db "00009200", 4, "FUNGUS    ", BR, BR
                db "00005010", 4, "KEV       ", BR, BR, 0
                
unref_Copyright:
                db 0xb5, 2, 7, 4
                db "COPYRIGHT GREMLIN GRAPHICS 1990", 0

                org 0x8214
unref_Sloppy:
                db "SLOPPY    "
                db 0xb8, 0x1e, 0x07, 0x47, 0x65, 0x66, 0 ; ??

                org 0x8225
                db 0xb8, 0x1e, 0x07, 0x47, 0x2a, 0x26, 0 ; ??

txt_Well_done
                db 0x14, 0, 6, 0x46
                db "WELL DONE! YOU HAVE A HIGH SCORE", BR, BR, 5
                db "PLEASE ENTER YOUR NAME", 0

txt_Well_done_pt_2
                db 0x3c, 0x14
                db 0x07, 0x47
                db "A B C D E F", BR, BR
                db "G H I J K L", BR, BR
                db "M N O P Q R", BR, BR
                db "S T U V W X", BR, BR
                db "Y Z !   < +", 0

txt_Well_done_selector
                ; selector square
                db 0x74, 0x26, 0x47, 7
                db 0x22, 0x23, 0x24, BR
                db 0x25, 0x01, 0x25, BR
                db 0x27, 0x28, 0x29, 0

                org 0x82be

txt_name_buffer:
                db 0x96, 0x14, 0x07, 0x04

name_buffer:    ; 10 bytes of name
                db 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
                db 0

txt_maybe_cursor
                ; cursor on the bottom of hiscore entry
                db 0xa0, 0x12, 7, 0x47
                db " / ", 0



                endmodule
