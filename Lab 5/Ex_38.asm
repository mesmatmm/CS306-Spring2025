
; File Name: .asm
; Date: 10-March-2025
; Author: Mahmoud Esmat

;include 'emu8086.inc'

org 100h

mov cx, 7
mov si, 0 
mov al, 0
mov ah, 0
L1:
    add al, data[si]   
    inc si    
    jnc L2
    adc ah, 0 
    L2:
Loop L1 
mov sum, ax 
mov bl, 8
div bl
mov AVGQ, al
mov AVGR, ah   


mov ax, 0B800h  ; Correct segment for display memory
mov es, ax      ; Set ES to point to the display memory segment

;The display address of the first character (H) = (81 - 1) x 2 = [160]

mov si, 0 
mov di, 160          
mov CX, 17            

L3:
  mov al, DISM[si]       ; Load the character from the string into AL
  mov es:[di], al       ; Write the character to the display memory
  add di, 2          ; Move to the next character position (skip attribute byte)
  inc si             ; Move to the next character in the string
LOOP L3



ret 
data db 7fh, 0b2h, 35h, 0feh, 0c9h, 80h, 9eh, 11h
sum dw ?
avgq db ?
avgr db ?
DISM db 'summation is done'  ;17 characters

