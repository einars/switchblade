                org 0x9a27
X9a27:
                ld l, 0x2b
                ld e, 0x2a
                ld a, (de) ; mach-DE[2a]
                dec a
                jp m, 1f

                ; ret_hl
                cp (hl)
                ret nc

1               ld a, e; EX L, E
                ld e, l
                ld l, a
                ld a, (de)
                cp (hl)
                jr c, .ret_0

                ld l, 0x2d
                ld e, 0x2c
                ld a, (de)
                dec a
                jp m, 2f
                cp (hl)
                ret nc

2               ld a, e ; EX L, E
                ld e, l 
                ld l, a

                ld a, (de)
                cp (hl)

.ret_0          ccf
                ret


.e_9a4b:
                ld l, 0
                push hl
                pop iy
.smc+*          ld a, 0b10101010 ; AA
                rlca
                ld (.smc), a
                jr c, 1f

.smc2           ld a, 0 ; frequently written: 9a59
.smc_9a59       equ $-1
                or a
                ; call X9a89 with either mach3 or mach9

                jr z, 2f
                ld d, 0x60
                call X9a89
                jr 2f

1               ld d, 0x66
                call X9a89
                
2               ld de, 0x6602
                ld a, (de) ; mach9[2]
                rla
                ret c
                ld d, 0x5d ; mach0
                call .entry1

                inc d
                ld b, 8

.lp             ld e, 2
                ld a, (de)
                and 4
                call nz, .entry1
                inc d
                djnz .lp

                xor a
                ld l, 0x1d
                or (hl)
                ret nz
                jr .entry2

.e_9a89:        ld e, 2
                ld a, (de)
                rra
                ret nc

.entry1         ld e, 0x1d
                ld a, (de) ; mach[1d]
                or a
                ret nz

                pop bc
                ex de, hl
                ld l, a
                push hl
                pop iy

.entry2         ld l, 0x1a
                ld e, (hl)
                ld l, 0x1d
                ld (hl), e
                ld l, 0x28
                or (hl)
                jr z, 2f
                dec (hl)
                jr z, 1f
                ld a, (hl)
                ld l, 0x1d
                ld (hl), a
                ret

1               xor a
                ld l, 0x0e
                or (hl)
                jp nz, J9087

2               call X98b6.entry_9987
                ld (smc_L9be9), a
                ld de, 0x73e5
                ld l, 0x2f
                ld b, 9

.lpp            inc e
                inc e
                inc l
                or (hl)
                jr nz, 6f ; JP *[word ptr HL]
                djnz .lpp

                ld l, 2
                bit 1, (hl)
                jp nz, L9cd9

                ld l, 0x10
                bit 4, (hl)
                jp nz, L904a

                bit 5, (hl)
                jp nz, L9163

                bit 2, (hl)
                jp nz, L90a6

                ld a, h
                cp 0x5d
                jr nz, 4f
                ld a, (Ueither_3210)
                or a
                jp nz, L926e

4               ld l, 3    ; jp machHL[3:4]
                ld c, (hl)
                inc l
                ld b, (hl)

.jp_bc          push bc
                pop ix
                jp (ix)

6               ex de, hl
                ld c, (hl)
                inc l
                ld b, (hl)
                ex de, hl
                jr .jp_bc
