
; File Name: Ex_13.asm
; Date: Day-Month-2025
; Author: Mahmoud Esmat

org 100h       ; Set the origin (starting address) of the program to 100h (typical for .COM files)

sale dw ?      ; Define a variable 'sale' of type word (16-bit), uninitialized
s_price dw ?   ; Define a variable 's_price' of type word (16-bit), uninitialized

mov ax, 6000   ; Load the original price (6000 LE) into the AX register
mov bx, 20     ; Load the sale rate (20%) into the BX register
mul bx         ; Multiply AX (6000) by BX (20), result in AX = 120000 (6000 * 20)

mov cx, 100    ; Load the value 100 into the CX register
div cx         ; Divide AX (120000) by CX (100), result in AX = 1200 (120000 / 100)
mov sale, ax   ; Store the sale amount (1200) in the 'sale' variable

mov cx, 6000   ; Load the original price (6000) into the CX register
sub cx, sale   ; Subtract the sale amount (1200) from the original price (6000), result in CX = 4800
mov s_price, cx ; Store the final sale price (4800) in the 's_price' variable

ret            ; Return from the program (end execution)




