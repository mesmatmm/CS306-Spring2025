org 100h  ; Set the origin (starting address) of the program to 100h (typical for .COM files)

mov al, var[0]  ; Load the first byte (80h) from the variable 'var' into the AL register
cbw            ; Convert the byte in AL to a word in AX (sign-extend AL to AX)
mov dx, ax     ; Move the value in AX (sign-extended 80h) to DX

mov al, var[1]  ; Load the second byte (0FFh) from the variable 'var' into the AL register
cbw            ; Convert the byte in AL to a word in AX (sign-extend AL to AX)
add ax, dx     ; Add the value in DX (sign-extended 80h) to AX (sign-extended 0FFh)
mov sum, ax    ; Store the result (sum) in the variable 'sum'

printn 'All done'  ; Print the message 'All done' to the screen (assuming this is a macro or function)

ret            ; Return from the program (end execution)

var db 80h, 0ffh  ; Define a byte array 'var' with two values: 80h and 0FFh
sum dw ?          ; Define a word-sized variable 'sum' to store the result (uninitialized)