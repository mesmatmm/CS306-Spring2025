
; File Name: .asm
; Date: 07-March-2025
; Author: Mahmoud Esmat

org 100h

;Convert Word to Double word.
;
;Algorithm:
;
;if high bit of AX = 1 then:
;   DX = 65535 (0FFFFh)
;
;else
;   DX = 0
;
;Example:  

MOV DX, 0   ; DX = 0
MOV AX, 0   ; AX = 0
MOV AX, -5  ; DX AX = 00000h:0FFFBh
CWD         ; DX AX = 0FFFFh:0FFFBh
RET

ret




