
; File Name: .asm
; Date: 10-March-2025
; Author: Mahmoud Esmat

include 'emu8086.inc'

org 100h

mov cx, 10
mov si, 0
mov al, 0
L1:
    cmp al, Grades[si] 
    JA L2
    mov al, Grades[si] 
    L2: 
    inc si
Loop L1  
mov Max_Grade, al
printn 'Maximum is detected' 
ret
 
Grades db 69, 87, 96, 45, 13, 55, 100, 73, 37, 66  ; 10 elements
Max_Grade db ?
Message db 'Maximum is detected'


