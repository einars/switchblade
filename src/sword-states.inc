                org 0x7f1d
Sword_states:
.one_based      equ $ - 6

; 6-byte char lists, one after another
                db 0x20, 0x67, 0x6a, 0x79, 0x79, 0x83
                db 0x67, 0x6b, 0x79, 0x7a, 0x79, 0x83
                db 0x67, 0x6b, 0x6c, 0x7b, 0x79, 0x83
                db 0x68, 0x6e, 0x6d, 0x7c, 0x79, 0x83
                db 0x69, 0x70, 0x6f, 0x7c, 0x79, 0x83
                db 0x69, 0x70, 0x7b, 0x7d, 0x79, 0x83
                db 0x69, 0x70, 0x71, 0x7d, 0x7a, 0x83
                db 0x69, 0x70, 0x72, 0x7d, 0x7d, 0x83
                db 0x69, 0x74, 0x73, 0x7d, 0x7d, 0x83
                db 0x69, 0x74, 0x73, 0x7d, 0x7d, 0x84
                db 0x69, 0x74, 0x75, 0x7d, 0x7d, 0x84
                db 0x69, 0x74, 0x75, 0x7d, 0x7d, 0x84
                db 0x69, 0x74, 0x76, 0x7d, 0x7e, 0x84
                db 0x69, 0x74, 0x76, 0x7d, 0x7f, 0x84
                db 0x69, 0x74, 0x77, 0x7d, 0x80, 0x84
                db 0x69, 0x74, 0x78, 0x82, 0x81, 0x84

; 1.
; ----------------------XX------------------------ 
; --------------X-------XX------------------------ 
; -------------XX-X-X-XXX--X-X-X-X-X-X-X-X-X------ 
; -------------XXXXXXXXXX-X-X-X-X-X-X-X-X-X-X-X-X- 
; -------------XX-X-X-XXX--X-X-X-X-X-X-X-X-X------ 
; --------------X-------XX------------------------ 
; ----------------------XX------------------------ 
; ------------------------------------------------ 
; 
; 2.
; --------------XX--------------------------------
; ------X-------XX--------------------------------
; -----XX-X-X-X-X--X-X-X-X-X-XXX-X-X-X-X-X-X------
; -----XXXXXXXXXX-X-X-X-X-X-XXXXX-X-X-X-X-X-X-X-X-
; -----XX-X-X-X-X--X-X-X-X-X-XXX-X-X-X-X-X-X------
; ------X-------XX--------------------------------
; --------------XX--------------------------------
; ------------------------------------------------
; 
; 3.
; --------------XX-XXXX---------------------------
; ------X-------XXXX------------------------------
; -----XX-X-X-X-X-XX-X-X-X-X-XXXXX-X-X-X-X-X------
; -----XXXXXXXXXX-XX--X-X-X-XXXXXXX-X-X-X-X-X-X-X-
; -----XX-X-X-X-X-XX-X-X-X-X-XXXXX-X-X-X-X-X------
; ------X-------XXXX------------------------------
; --------------XX-XXXX---------------------------
; ------------------------------------------------
; 
; 4.
; ----------XX-XXXX------------------------------- 
; --X-------XXXX---------------------------------- 
; -XX-X-X-X-X-XX-X-X-X-X-XXXXXXX-X-X-X-X-X-X------ 
; -XXXXXXXXXXXXX--X-X-X-XXXXXXXXX-X-X-X-X-X-X-X-X- 
; -XX-X-X-X-X-XX-X-X-X-X-XXXXXXX-X-X-X-X-X-X------ 
; --X-------XXXX---------------------------------- 
; ----------XX-XXXX------------------------------- 
; ------------------------------------------------ 
; 
; 5.
; -----XXXX-XX-XXXX-------------------------------
; --X------XXXXX----------------------------------
; -XX-X-X-XXX-XX-X-X-X-XXXXXXXXX-X-X-X-X-X-X------
; -XXXXXXXXXXXXX--X-X-XXXXXXXXXXX-X-X-X-X-X-X-X-X-
; -XX-X-X-XXX-XX-X-X-X-XXXXXXXXX-X-X-X-X-X-X------
; --X------XXXXX----------------------------------
; -----XXXX-XX-XXXX-------------------------------
; ------------------------------------------------
; 
; 6.
; -----XXXX-XX-XXX--------------------------------
; --X------XXXXX----------------------------------
; -XX-X-X-XXX-XX-X-X-XXXXXXXXXXXXX-X-X-X-X-X------
; -XXXXXXXXXXXXX--X-XXXXXXXXXXXXXXX-X-X-X-X-X-X-X-
; -XX-X-X-XXX-XX-X-X-XXXXXXXXXXXXX-X-X-X-X-X------
; --X------XXXXX----------------------------------
; -----XXXX-XX-XXX--------------------------------
; ------------------------------------------------
; 
; 7.
; -----XXXX-XX-XXXX-------------------------------
; --X------XXXXX----------------------------------
; -XX-X-X-XXX-XX-X-XXXXXXXXXXXXXXX-X-XXX-X-X------
; -XXXXXXXXXXXXX--XXXXXXXXXXXXXXXXX-XXXXX-X-X-X-X-
; -XX-X-X-XXX-XX-X-XXXXXXXXXXXXXXX-X-XXX-X-X------
; --X------XXXXX----------------------------------
; -----XXXX-XX-XXXX-------------------------------
; ------------------------------------------------
; 
; 8.
; -----XXXX-XX-XXXXX------------------------------
; --X------XXXXX----------------------------------
; -XX-X-X-XXX-XX-XXXXXXXXXXXXXXXXXXXXXXXXX-X------
; -XXXXXXXXXXXXX--XXXXXXXXXXXXXXXXXXXXXXXXX-X-X-X-
; -XX-X-X-XXX-XX-XXXXXXXXXXXXXXXXXXXXXXXXX-X------
; --X------XXXXX----------------------------------
; -----XXXX-XX-XXXXX------------------------------
; ------------------------------------------------
; 
; 9.
; -----XXXX-XX-XXXXX------------------------------
; --X------XXXXX-----XX---------------------------
; -XX-X-X-XXX-XXXXXXXXXXXXXXXXXXXXXXXXXXXX-X------
; -XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX-X-X-X-
; -XX-X-X-XXX-XXXXXXXXXXXXXXXXXXXXXXXXXXXX-X------
; --X------XXXXX-----XX---------------------------
; -----XXXX-XX-XXXXX------------------------------
; ------------------------------------------------
; 
; 10.
; -----XXXX-XX-XXXXX------------------------------
; --X------XXXXX-----XX---------------------------
; -XX-X-X-XXX-XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX-----
; -XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX-
; -XX-X-X-XXX-XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX-----
; --X------XXXXX-----XX---------------------------
; -----XXXX-XX-XXXXX------------------------------
; ------------------------------------------------
; 
; 11.
; -----XXXX-XX-XXXXX--X---------------------------
; --X------XXXXX-----XXX--------------------------
; -XX-X-X-XXX-XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX-----
; -XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX-
; -XX-X-X-XXX-XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX-----
; --X------XXXXX-----XXX--------------------------
; -----XXXX-XX-XXXXX--X---------------------------
; ------------------------------------------------
; 
; 12.
; -----XXXX-XX-XXXXX--X---------------------------
; --X------XXXXX-----XXX--------------------------
; -XX-X-X-XXX-XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX-----
; -XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX-
; -XX-X-X-XXX-XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX-----
; --X------XXXXX-----XXX--------------------------
; -----XXXX-XX-XXXXX--X---------------------------
; ------------------------------------------------
; 
; 13.
; -----XXXX-XX-XXXXX--X---------------------------
; --X------XXXXX-----XXXXX------------X--X--------
; -XX-X-X-XXX-XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX-----
; -XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX-
; -XX-X-X-XXX-XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX-----
; --X------XXXXX-----XXXXX------------X--X--------
; -----XXXX-XX-XXXXX--X---------------------------
; ------------------------------------------------
; 
; 14.
; -----XXXX-XX-XXXXX--X---------------X-----------
; --X------XXXXX-----XXXXX----------XXXX-X--------
; -XX-X-X-XXX-XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX-----
; -XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX-
; -XX-X-X-XXX-XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX-----
; --X------XXXXX-----XXXXX----------XXXX-X--------
; -----XXXX-XX-XXXXX--X---------------X-----------
; ------------------------------------------------
; 
; 15.
; -----XXXX-XX-XXXXX-XXX--------------X-----------
; --X------XXXXX----XXXXXX----------XXXXXX--------
; -XX-X-X-XXX-XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX-----
; -XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX-
; -XX-X-X-XXX-XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX-----
; --X------XXXXX----XXXXXX----------XXXXXX--------
; -----XXXX-XX-XXXXX-XXX--------------X-----------
; ------------------------------------------------
; 
; 16.
; -----XXXX-XX-XXXXX-XXXXX----------XXXX----------
; --X------XXXXX----XXXXXXXX------XXXXXXXX--------
; -XX-X-X-XXX-XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX-----
; -XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX-
; -XX-X-X-XXX-XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX-----
; --X------XXXXX----XXXXXXXX------XXXXXXXX--------
; -----XXXX-XX-XXXXX-XXXXX----------XXXX----------
; ------------------------------------------------
; 

