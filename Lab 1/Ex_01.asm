

org 100h

; Task a: Initialize AX and SI registers
MOV AX, 1520H       ; Load AX with immediate value 1520H
MOV SI, 0300H       ; Load SI with immediate value 0300H

; Task b: Save the immediate value 3040H at the memory location addressed by SI
MOV [SI], 3040H    ; Store 3040H at the memory location pointed to by SI

; Task c: Add the word contents at the memory location addressed by SI to AX
ADD AX, [SI]       ; Add the value at memory location [SI] to AX

ret




