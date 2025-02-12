org 100h        ; Set the origin to 100h (typical for COM programs in DOS)

; Task a: Initialize AL and SI registers
MOV AL, 33H         ; Load AL with immediate value 33H
MOV SI, 0300H       ; Load SI with immediate value 0300H

; Task b: Copy 55H to the data segment memory location addressed by SI
MOV [SI], 55H       ; Store 55H at the memory location pointed to by SI

; Swap between AL and the data at the data segment memory location addressed by SI
XCHG AL, [SI]       ; Swap AL with the value at memory location [SI]


ret             ; Return to the operating system (end of the program)