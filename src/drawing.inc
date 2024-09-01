                org 0x8c68

Drawing_routine:
                ; intro time func
                ld a, (logo_row_ish)
                ld e, a
                ld a, (logo_col_ish)

                call Get_some_screen_addr ; in A + E, A — col-ish (div 3, etc), E — row

                ld h, 0x5d ; high(mach0)
                ld bc, 0x004a ; smc B
.pipe_b_param   equ $-1
                call Patch_and_blit

                ld hl, Blit_char
                dec a ; A = bytes_to_move to screen. 1? Blit_char, otherwise, Blit_line
                jr z, 3f
                ld l, 0x16

2               dec l
                dec l
                dec a
                jr nz, 2b ; L = 0x16 - 2*A

                ld a, l
                ld (Blit_line.smc_reljump), a ; sets the number of LDI operations
                ld hl, Blit_line

3               ld (.cb_char_or_line), HL
                ld a, (Patch_and_blit.n_lines)
                rra
                rra
                rra
                and 0x1f
                ld b, a

                ld hl, L6f08

.loop           ld c, d
                push bc

.cb_char_or_line equ $+1
                call 0 ; sic: smc obvs. Either Blit_char or Blit_line

                ld a, e
                add a, 0x20
                ld e, a
                pop bc
                jr c, .next
                ld d, c
.next           djnz .loop
                ret

Blit_line:
                ; height = 1 char / 8 lines
                ; masked at the beginning / end character
                ; via .mask_1 and .mask_2
                ld bc, 0x08ff

.loop           push de
                ld a, (de)
.mask_1+*       and 0
                or (hl)
                ld (de), a
                inc hl
                inc de
.smc_reljump    equ $+1
                jr .move_0
                ldi
                ldi
                ldi
                ldi
                ldi
                ldi
                ldi
                ldi
                ldi
                ldi
.move_0         ld a, (de)
.mask_2+*       and 0
                or (hl)
                ld (de), a
                inc hl
                pop de
                inc d
                djnz .loop
                ret


Blit_char:
                ld b, 8
.loop           ld a, (de)
.mask+*         and 0
                or (hl)
                ld (de), a
                inc hl
                inc d
                djnz .loop
                ret

                org 0x8ce5

Patch_and_blit:
                ; take a part of the Blitter_codes,
                ; choose starting point and end point from Blitter_patches
                ; and execute it
                push de
                ld l, c
                push hl
                ld a, (logo_col_ish) ; 1 
                and 7

                ld l, a
                add a, a
                add a, l
                add a, 0x98
                ld l, a ; 0x98 + (logo_col_ish & 7) * 3
                ld h, 0xfd

                ; fd9b .. fdce

                ; 1b: FDA1, B = 06, FDC8

                ld e, (hl)
                inc l
                ld d, (hl)
                inc l
                ld a, (hl)
                ld (.callback), de
                ld (Blit_line.mask_1), a

                push af

                ld de, 0x13
                add hl, de

                ld a, b
                add a, a
                add a, b
                ld e, a

                add hl, de ; &entry_last_byte + 0x13 + N*3

                ld e, (hl)
                inc l
                ld d, (hl) ; DE will get patched w/return?!
                inc l
                ld a, (hl)
                ex de, hl
                ld (.store_addr), hl
                ld (Blit_line.mask_2), a

                pop bc
                or b

                ld (Blit_char.mask), a ; mask_1 | mask_2

                ld a, (hl)
                ld (hl), 0xc9 ; HMMM: temporarily override .store_addr with RET, then restore
                ld (.store_val), a

                ld bc, L6f08
                pop hl

.n_lines+*      ld a, 0
.loop           push af
                push hl
                xor a
                push bc
.callback       equ $+1
                call 0
                ld (bc), a
                inc bc
                pop de
                pop hl
                pop af
                inc l
                dec a
                jr nz, .loop

                ld l, c
                ld h, b
                or a
                sbc hl, de
                ld a, l

.store_addr+*   ld hl, 0
.store_val+*    ld (hl), 0
                pop de
                ret

                ; 84d5..84fd
                ; A long mass of code, a fragment of which gets patched up with RET and executed

                org 0x8d45


.Blitter_codes
.sta_45         ld a, (hl)
                rrca
                rrca
                rrca
                inc h           ;; 8d49

.sta_4a         ld e, a
                ld a, (hl)      
                rlca
                rlca
                or e
                inc h           ;; 8d4f

.sta_50         ld d, 0
                ld e, (hl)      
                srl e
                rr d
                or e
                ld (bc), a
                inc bc
                ld a, d
                inc h           ;; 8d5b

.sta_5c         ld e, a
                ld a, (hl)
                rrca : rrca : rrca : rrca
                or e
                inc h           ;; 8d63

.sta_64         ld e, a
                ld a, (hl)
                rlca
                or e
                inc h           ;; 8d68

.sta_69         ld d, 0
                ld e, (hl)
                srl e : rr d
                srl e : rr d
                or e
                ld (bc), a
                inc bc
                ld a, d
                inc h           ;; 8d78

.sta_79         ld e, a
                ld a, (hl)
                rlca : rlca : rlca
                or e
                inc h           ;; 8d7f

.sta_80         or (hl)
                ld (bc), a      ;;; 8d81
                inc bc
                inc h
                ld a, (hl)
                rrca : rrca : rrca
                inc h           ;; 8d88

                ld e, a
                ld a, (hl)
                rlca : rlca
                or e
                inc h           ;; 8d8e
                ld d, 0
                ld e, (hl)
                srl e : rr d
                or e
                ld (bc), a
                inc bc
                ld a, d
                inc h           ;; 8d9a

                ld e, a
                ld a, (hl)
                rrca : rrca : rrca : rrca
                or e
                inc h           ;; 8da2

                ld e, a
                ld a, (hl)
                rlca
                or e
                inc h           ;; 8da7

                ld d, 0
                ld e, (hl)
                srl e : rr d
                srl e : rr d
                or e
                ld (bc), a
                inc bc
                ld a, d
                inc h           ;; 8db7

                ld e, a
                ld a, (hl)
                rlca : rlca : rlca
                or e
                inc h           ;; 8dbe

                or (hl)
                ld (bc), a
                inc bc
                inc h           ;; 8dc2

                ld a, (hl)
                rrca : rrca : rrca
                inc h           ;; 8dc7

                ld e, a
                ld a, (hl)
                rlca : rlca
                or e
                inc h           ;; 8dcd

                ld d, 0
                ld e, (hl)
                srl e : rr d
                or e
                ld (bc), a
                inc bc
                ld a, d
                inc h           ;; 8dd9

                ld e, a
                ld a, (hl)
                rrca : rrca : rrca : rrca
                or e
                inc h           ;; 8de1

                ld e, a
                ld a, (hl)
                rlca
                or e
                inc h           ;; 8de6

                ld d, 0
                ld e, (hl)
                srl e : rr d
                srl e : rr d
                or e
                ld (bc), a
                inc bc
                ld a, d
                inc h           ;; 8df6

                ld e, a
                ld a, (hl)
                rlca : rlca : rlca
                or e
                inc h           ;; 8dfd














                org 0xfd98
.Blitter_patches
                dw .sta_45 : db 0x00
                dw .sta_4a : db 0xe0
                dw .sta_50 : db 0xfc
                dw .sta_5c : db 0x80 ; 1B / 6 Start
                dw .sta_64 : db 0xf0
                dw .sta_69 : db 0xfe
                dw .sta_79 : db 0xc0
                dw .sta_80 : db 0xf8

                dw 0x8d49 : db 0x1f ;;
                dw 0x8d4f : db 0x03 ;;
                dw 0x8d5b : db 0x7f ;;
                dw 0x8d63 : db 0x0f ;;
                dw 0x8d68 : db 0x01 ;;
                dw 0x8d78 : db 0x3f ;;
                dw 0x8d7f : db 0x07 ;;
                dw 0x8d81 : db 0x00 ;;;
                dw 0x8d88 : db 0x1f ;; 1B / 6 Finish

                dw 0x8d8e : db 0x03 ;;
                dw 0x8d9a : db 0x7f ;;
                dw 0x8da2 : db 0x0f ;;
                dw 0x8da7 : db 0x01 ;;
                dw 0x8db7 : db 0x3f ;;
                dw 0x8dbe : db 0x07 ;;
                dw 0x8dc0 : db 0x00 ;;
                dw 0x8dc7 : db 0x1f ;;
                dw 0x8dcd : db 0x03 ;;
                dw 0x8dd9 : db 0x7f ;;
                dw 0x8de1 : db 0x0f ;;
                dw 0x8de6 : db 0x01 ;;
                dw 0x8df6 : db 0x3f ;;
                dw 0x8dfd : db 0x07 ;;

                org 0xfdf5
