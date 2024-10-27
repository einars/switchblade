                module Print

                ; generally,
                ; DE — coordinates
                ; HL — text pointes


                org 0x8365
Write_sys_top_bottom:
                ld hl, Uscore_text
                call String_alt

                org 0x836b
Write_sys_bottom:
                ld hl, Ubottom_text

Text:
                ld bc, SMC_print_1
                ld a, (hl)
                and 7
                jr z, 1f
                ld bc, SMC_print_2
                xor a
1               ld (bc), a
                ; either store 0 into SMC_print_1
                ; or 0 into SMC_print_2, hmm

String_alt:     ld bc, LetterGlyphs
                push bc
                ld b, (hl)
                inc hl
                ld c, (hl)
                ; BC = coords
                inc hl
                ld a, (hl)
                inc hl
                ld (attrib_dn), a
                ld a, (hl)
                inc hl
                ld (attrib_up), a

                push hl
                call Screen_addr
                pop hl
                pop bc

2               ld a, (hl)
                inc hl
                or a
                jr nz, 1f
                ; A = 0 -> text ends
                dec a ; a = 0xff now, reset all flags to Ff
                ld (attrib_dn), a
                ld (attrib_up), a
                ld (SMC_print_2), a
                ld (SMC_print_1), a
                ret

1               push bc
                push hl
                ld h, 0
                cp 0xff
                jr z, .handle_ff
                cp 0x20
                jr c, .handle_sub_20
                ; common glyph
                sub 0x20
                ld l, a
                add hl, hl
                add hl, hl
                add hl, hl
                add hl, bc
                call Print.Char

.next_char
                pop hl
                pop bc
                jr 2b

.handle_sub_20
                ; chars < 20 are treated as that number of spaces
                ld l, a
                add hl, de
                ex de, hl
                jr .next_char

.handle_ff
.next_line_coord+*      ld bc, 0
                call Screen_addr
                jr .next_char

Screen_addr:
                push bc
                ld a, 8
                add a, b
                ld b, a ; y = y + 8
                ld (String_alt.next_line_coord), bc 
                pop bc
                srl c
                ld a, b
                and 7
                ld d, a
                ld a, b
                and 0xf8
                rrca
                rrca
                rrca
                ld b, a
                jr 1f

;X83e6:
Screen_addr_alt:
                ; screen addr of BC (B — char-row, 0..23, C — char-column, 0..32)
                ; 0-th row is actually first char-row
                inc b
                ld d, 0
                ld a, b
1               and 0xf8
                add 0x40
                add a, d
                ld d, a
                ld a, b
                and 7
                rrca
                rrca
                rrca
                add a, c
                ld e, a
                ret

Char:    
                push de
attrib_up+*     ld a, 0xff
                call StoreAttrib
                ld a, d
                and 7
                ld c, a
                ld a, 8
                sub c
                ld b, a

2               ld a, (hl)
                ld (de), a

                inc hl
                inc d
                ld a, b
                cp 4
                jr nz, 1f

SMC_print_1+*   ld a, 0xff ; flag — repeat line 4?
                or a
                jr nz, 1f
                dec hl
1               djnz 2b
                
                ld a, c
                or a
                jr z, quit

SMC_print_2+*   ld a, 0xff
                or a
                jr nz, 1f
                inc c
                dec hl
1               ld a, e
                add a, 32
                ld e, a
                jr c, 2f

                pop af
                push af
                and 0xf8
                ld d, a

2               ld b, c
                
                ; print b lines downwards
3               ld a, (hl)
                ld (de), a
                inc hl
                inc d
                djnz 3b

attrib_dn+*     ld a, 0xff
                call StoreAttrib

quit            pop de
                inc de
                ret

StoreAttrib:
                ; de = x/y
                ; a = attrib
                push de
                push af
                ld a, d
                rrca
                rrca
                rrca
                and 3
                or 0x58
                ld d, a
                pop af
                cp 0xff
                jr z, 1f
                ld (de), a
1               pop de
                ret


                endmodule

