
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

; Task a: Initialize AX and DX registers
MOV AX, 1234H       ; Load AX with immediate value 1234H
MOV DX, 5678H       ; Load DX with immediate value 5678H

; Task b: Subtract the word content of AX from the word content of DX
SUB DX, AX          ; Subtract AX from DX, result stored in DX

ret




