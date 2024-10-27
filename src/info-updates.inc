                org 0xff64
                
Update_hit_and_energy_display:
                ; update some attributes if Uhit_power or Uenergy changed
                ld hl, Uhit_power
                ld a, (hl)
                inc hl
                cp (hl)
                jr z, 1f

                ld de, 0x51f8 ; fire_power bar screen address
                call .draw_bar_at_de

1               ld hl, Uenergy
                ld a, (hl)
                inc hl
                cp (hl)
                ret z ; no change in Uenergy

                ld de, 0x51e0 ; energy bar screen address


.draw_bar_at_de
                ld (hl), a

                ld a, 0xff
                ld (bar_end_ptr), a

                ld c, 0xbb
                ld a, (hl)
                cp 0x20
                jr z, 2f
                ld c, 0xc3
                or a
                jr z, 2f
                and 3
                ld bc, bar_patterns
                add a, c
                ld c, a
                ld a, (bc)
                ld (bar_end_ptr), a ; patterns

                ld a, (hl)
                srl a
                srl a
                ld c, a
                ld a, 0xc2
                sub c
                ld c, a ; c = 0xc2 - (*hl / 4)
2               ld h, 0xff
                ld l, c
                ld b, 6

                ; display the correct number of bars on screen
                ; some amount of 11111111s, bar end, some amount of 01010101s
.loop           push hl
                push de
                push bc
                ld bc, 8
                ldir
                pop bc
                pop de
                pop hl
                inc d
                djnz .loop

                ret

                org 0xffb7
bar_patterns    db 0b01010101
                db 0b11010101
                db 0b11110101
                db 0b11111101

                ; some offset 8 bytes from this will bet displayed as an energy/power bar
                db 0b11111111
                db 0b11111111
                db 0b11111111
                db 0b11111111
                db 0b11111111
                db 0b11111111
                db 0b11111111
bar_end_ptr     db 0b11111111 ; replaced with the actual pattern
                db 0b01010101
                db 0b01010101
                db 0b01010101
                db 0b01010101
                db 0b01010101
                db 0b01010101
                db 0b01010101
                db 0b01010101
