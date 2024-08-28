; title sprites and texts

                module Intro

                org 0x6313

Tiles:          include "intro-tiles.inc"



                org 0x5e4d

Sprite_00:
                db 0x98, 0x32; coords
                db 0xce, 0xcf, 0xd0, 0xd1, 0xd2,    1, 0xff
                db 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 0xd8, 0xff
                db 0xd9, 0xda, 0xdb, 0xdc, 0xdd, 0xde, 0x00

                db 0x60, 0x02, 0x07, 0x47
                db "FOR 10000 YEARS HE SLEPT.", 0xff
                db "HIS MIND FEEDING...", 0xff
                db "ON THE NIGHTMARES OF THE WEAK.", 0x00

                ; pause for fire

                db 0x60, 0x02, 0x07, 0x47
                db "                         ", 0xff
                db "NOW HE HAS AWAKENED", 0xff
                db "                              ", 0x00

                ; 5f06


                endmodule
