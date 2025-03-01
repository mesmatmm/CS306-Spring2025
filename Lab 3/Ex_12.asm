
; File Name: Ex_12.asm
; Date: Day-Month-2025
; Author: Mahmoud Esmat

org 100h       ; Set the origin (starting address) of the program to 100h (typical for .COM files)

sum dw ?       ; Define a variable 'sum' of type word (16-bit), uninitialized

mov al, 6      ; Load the value 6 into the AL register (AL = 6)
mov bl, 7      ; Load the value 7 into the BL register (BL = 7)

mul bl         ; Multiply AL by BL (6 * 7 = 42), result stored in AX (16-bit result)

mov cl, 2      ; Load the value 2 into the CL register (CL = 2)
div cl         ; Divide AX by CL (42 / 2 = 21), result stored in AL (quotient)

mov sum, ax    ; Move the result in AX (21) into the 'sum' variable

ret            ; Return from the program (end execution)




