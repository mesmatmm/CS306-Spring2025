org 100h        ; Set the origin to 100h (typical for COM programs in DOS)

; A) Initialize AX register by FF00h
MOV AX, 0FF00H

; Set the rightmost 8 bits of AX 
OR AX, 0000000011111111B
;OR AX, 00FFH

; Clear bits 8 and 9 of AX     
AND AX, 0000111111001111B
;AND AX, 0FCFFH

; Invert the leftmost 6 bits of AX and store the result in BX
MOV BX, AX   
XOR BX, 1111110000000000B
;XOR BX, 0FC00H  ; Invert the leftmost 6 bits

; B) Initialize the low order byte of CX by EFh and save its one's complement at the high order byte
MOV CL, 0EFH
MOV CH, CL
NOT CH          ; One's complement of EFh

; C) Initialize the low order byte of DX by EFh and save its 2's complement at the high order byte
MOV DL, 0EFH
MOV DH, DL
NEG DH          ; Two's complement of EFh

ret             ; Return to the operating system (end of the program)
