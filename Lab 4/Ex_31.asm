
; File Name: Ex_31.asm
; Date: 03-March-2025
; Author: Mahmoud Esmat

org 100h         ; Set the origin at memory address 100h

mov ax, 800h    ; Load segment address 0800h into AX
mov ds, ax      ; Set DS (Data Segment) to 0800h

mov si, 200h    ; Set SI to start of first block (0800h:0200h)
mov cx, 1024    ; Set loop counter for 1 Kbyte (1024 bytes)
mov di, 600h    ; Set DI to start of second block (0800h:0600h)

; Fill block1 with 7Eh and block2 with E7h
Blocks:
    mov [si], 7eh  ; Store 7Eh in block1 at address SI
    mov [di], 0e7h ; Store E7h in block2 at address DI
    inc si         ; Move to the next byte in block1
    inc di         ; Move to the next byte in block2
loop Blocks        ; Repeat for 1024 bytes

; Reset SI and DI to the start of the blocks for exchange
mov si, 200h    ; Reset SI to start of block1
mov di, 600h    ; Reset DI to start of block2
mov cx, 1024    ; Reset loop counter for exchange process

; Exchange block1 and block2 contents
Exchange:
    mov al, [si]  ; Load value from block1 into AL
    xchg al, [di] ; Swap AL with value in block2
    mov [si], al  ; Store exchanged value in block1
    inc si        ; Move to next byte in block1
    inc di        ; Move to next byte in block2
loop Exchange     ; Repeat for 1024 bytes

ret               ; Return to operating system
