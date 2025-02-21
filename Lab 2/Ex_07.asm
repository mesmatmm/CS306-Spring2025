

org 100h        ; Set the origin to 100h (typical for COM programs in DOS)

; Task a: Initialize AX, BX, and DI registers
MOV AX, 1020H       ; Load AX with immediate value 1020H
MOV BX, 3040H       ; Load BX with immediate value 3040H
MOV DI, 0200H       ; Load DI with immediate value 0200H

; Task b: One's complement the low byte of AX register
NOT AL              ; One's complement of AL (low byte of AX)

; Task c: Two's complement the high byte of BX register
NEG BH              ; Two's complement of BH (high byte of BX)

; Task d: Save the high byte of AX and the low byte of BX at memory locations addressed by DI
MOV [DI], AH        ; Save AH (high byte of AX) at memory location [DI]
MOV [DI+1], BL      ; Save BL (low byte of BX) at memory location [DI+1]

ret             ; Return to the operating system (end of the program)
