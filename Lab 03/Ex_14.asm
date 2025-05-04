
; File Name: Ex_14.asm
; Date: Day-Month-2025
; Author: Mahmoud Esmat

org 100h       ; Set the origin (starting address) of the program to 100h (typical for .COM files)

Data db 25h, 4fh, 85h, 1fh, 2bh, 0c4h  ; Define the 'data' array with the given byte values
copy db 6 dup(?)                        ; Define the 'copy' array with 6 uninitialized elements

; Direct Addressing Method 
mov al, data[0]
mov copy[0], al 
 ; ; ;
 ; ; ; 
 
; index addressing method
mov si, 0      ; Initialize the SI register (index register) to 0
mov al, data[si] ; Move the first element of the 'data' array (25h) into the AL register
mov copy[si], al ; Move the value in AL (25h) into the first element of the 'copy' array

inc si          ; Increment SI to point to the next index (SI = 1)
mov al, data[si] ; Move the second element of the 'data' array (4Fh) into the AL register
mov copy[si], al ; Move the value in AL (4Fh) into the second element of the 'copy' array

inc si          ; Increment SI to point to the next index (SI = 2)
mov al, data[si] ; Move the third element of the 'data' array (85h) into the AL register
mov copy[si], al ; Move the value in AL (85h) into the third element of the 'copy' array

inc si          ; Increment SI to point to the next index (SI = 3)
mov al, data[si] ; Move the fourth element of the 'data' array (1Fh) into the AL register
mov copy[si], al ; Move the value in AL (1Fh) into the fourth element of the 'copy' array

inc si          ; Increment SI to point to the next index (SI = 4)
mov al, data[si] ; Move the fifth element of the 'data' array (2Bh) into the AL register
mov copy[si], al ; Move the value in AL (2Bh) into the fifth element of the 'copy' array

inc si          ; Increment SI to point to the next index (SI = 5)
mov al, data[si] ; Move the sixth element of the 'data' array (0C4h) into the AL register
mov copy[si], al ; Move the value in AL (0C4h) into the sixth element of the 'copy' array

ret             ; Return from the program (end execution)







