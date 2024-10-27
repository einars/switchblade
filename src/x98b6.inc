                org 0x98b6
X98b6:
                ld hl, maybe_sound_to_play
                ld (hl), 8
                call Xa652
                ex de, hl
                inc hl
                cp 7
                jr c, .handle_sub7
                cp 0x11
                jp c, .handle_89abcdef
                cp 0x19
                jr c, .handle_to_18
                jr z, .handle_19
                cp 0x1a
                jr z, .handle_1a
                cp 0x1b
                jr z, .handle_1b
                cp 0x1c
                jr z, .handle_1c
                cp 0x1d
                jr z, .handle_1d
                cp 0x1e
                jr z, .handle_1e
                ld bc, 0x355
                cp 0x1f
                jr z, .handle_1f

.handle_sub7
                ld e, (hl)
                jr .leave_with_e


.handle_to_18
                ld a, (hl)
                or a
                call nz, .entry_9908
                inc hl

.entry_98f3     ld a, (hl)
                ld de, 0x6671 ; a bit after userdata
                ldi
                inc a
                ld (de), a
                ld a, (hl)
                ld (U09), a
                or a
                jr z, 1f
.loop
                ld a, 0x10
1               ld (Umaybe_is_alive), a
                ret

.entry_9908     ld e, a
                call X99e7
                ; SWORD FOUND
                push hl
                call X965f
                ld hl, Usword_parts
                inc (hl)
                bit 4, (hl)
                pop hl
                jr z, 2f

                ld e, 0xc6
                jr .leave_with_e

2               pop hl
                ret

.handle_1b
                ld a, (U09)
                or a
                jr nz, .loop


                ld e, 0x82
.leave_with_e
                jp X99e7

.handle_19
                ld hl, U05
                ld a, 2
                add a, (hl)
                cp 0x11
                ret nc
                ld (hl), a
                ld (Uhit_power), a
                ret

.handle_1a
                ld hl, U02 ; counter 0, 1, 2, 3 -> no-more
                ld a, 1
                add a, (hl)
                cp 4
                ret nc
                ld (hl), a
                ret

.handle_1c
                ld a, 0
                ld (U05), a
                ld (Uhit_power), a
                jr .done_8e

.handle_1d
                ld a, 1
                ld (U02), a

.done_8e        ld e, 0x8e
                jr .leave_with_e

.handle_1e      ld a, 0x20
                ld (Uenergy), a
                ret

.entry_995c
                ld hl, L651e
                ld c, (hl)
                inc l
                ld b, (hl)

.handle_1f
                push bc
                ld hl, 0x6500
                ld bc, (0x6500)
                ld a, (0x6502)
                rra
                jr c, 1f
                ld bc, (0x5d00)
                ld a, b
                add a, 8
                ld b, a
1               ld de, 0x6594
                ld a, 0x48
                call Xa65d
                ld (U0f), a
                ex de, hl
                pop bc
                jr .entry_9991

.entry_9987     ld l, 0x1c ; return if bit 7 of [1c] = 0
                bit 7, (hl)
                ret z
                res 7, (hl)
                ld bc, 0xff

.entry_9991     ld l, 0x1e ; [1e:1f] = BC
                ld (hl), c
                inc l
                ld (hl), b
                ret


.handle_89abcdef
                inc hl
                ld a, 0x47
                inc hl
                ld l, (hl)
                ld h, 0x5a
                ld (hl), a

                ld hl, ggggg
                ld de, 0x5ae9
                call .compare_5
                jr nz, 1f
                ld hl, bbbbbggggg
                ldir
                ld hl, U0b
                ld a, 1
                ld (L79ff), a
                add a, (hl)
                daa
                ld (hl), a ; get extra life as EXTRA is full?
                ld b, 1
                ld de, Ulives_ascii
                jr BCD_to_ASCII

1               ld hl, ggggg
                ld de, 0x5af2
                call .compare_5
                ret nz

                ld hl, bbbbbggggg
                ldir
                ld a, 2
                ld (L79ff), a

                ; BONUS full
                ld e, 0xc2
                jr X99e7

.compare_5      ; compare 5 bytes
                ld bc, 0x505
                push de
.lp             ld a, (de)
                cp (hl)
                jr nz, .lp_done
                inc hl
                inc de
                djnz .lp
.lp_done        pop de
                ret

; 99e7

