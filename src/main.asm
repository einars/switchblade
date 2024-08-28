                device zxspectrum48

                org 0x4010

Start:
                ld sp, 0x5c00
                xor a
                out (0xfe), a
                ld a, 0xfe
                ld i, a 
                im 2
                jp 0x5cfa

                include "wip.asm"

	savesna "switchblade.sna", Start
