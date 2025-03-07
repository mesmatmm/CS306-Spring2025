
; File Name: .asm
; Date: 07-March-2025
; Author: Mahmoud Esmat

org 100h

;Convert byte into word.
;
;Algorithm:
;
;if high bit of AL = 1 then:
;    AH = 255 (0FFh)
;
;else
;    AH = 0
;
;Example:  

MOV AX, 0   ; AH = 0, AL = 0
MOV AL, -5  ; AX = 000FBh (251)
CBW         ; AX = 0FFFBh (-5)
RET

ret




