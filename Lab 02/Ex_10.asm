

; File Name: .asm
; Date: 11-Feb-2025
; Author: Mahmoud Esmat

org 100h

area DW ?        ; Variable to store the area of the rectangle
half_area DW ?   ; Variable to store half of the area
%DW = Define WORD 
 
; Initialize dimensions
MOV AL, 7H       ; Load 7h into AL
MOV BL, 3H       ; Load 3h into BL

; Calculate the area (7h * 3h)
MUL BL           ; AX = AL * BL (7h * 3h = 15h)
MOV area, AX     ; Save the area into the 'area' variable

; Calculate half of the area (15h / 2)  
MOV BL, 2
DIV BL        ; Divide AX by 2 (15h / 2 = 0Ah with remainder 1)    
              ; result will be in AX
MOV half_area, AX ; Save half of the area into the 'half_area' variable

; End of program
MOV AH, 4CH
INT 21H

ret




