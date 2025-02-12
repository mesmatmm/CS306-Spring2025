org 100h        ; Set the origin to 100h (typical for COM programs in DOS)

; Task a: Copy the string data 'NO' into AX register
MOV AX, 'NO'        ; Load AX with the string 'NO' (4F4E in hexadecimal)

; Initialize SI and BP registers
MOV SI, 0200H       ; Load SI with 0200H
MOV BP, 0100H       ; Load BP with 0100H

; Copy AX into stack segment memory location addressed by SI+BP+20H
MOV SS:[SI+BP+20H], AX  ; Copy AX to stack segment memory location SI+BP+20H

; Task b: Initialize DI with 0300H
MOV DI, 0300H       ; Load DI with 0300H

; Copy the string 'HELLO' into extra data segment memory locations addressed by DI+100H       
MOV ES:[DI+100H], 'HE' ; Copy 'HE' to memory location DI+100H in extra segment
MOV ES:[DI+102H], 'LL'  ; Copy 'LL' to memory location DI+102H in extra segment
MOV ES:[DI+104H], 'O' ; Copy 'O' to memory location DI+104H in extra segment

ret             ; Return to the operating system (end of the program)