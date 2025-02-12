
;Ex_03.asm

org 100h

; Task a: Initialize AL, BL, CL, and DL registers
MOV AL, 10H         ; Load AL with immediate value 10H
MOV BL, 20H         ; Load BL with immediate value 20H
MOV CL, 30H         ; Load CL with immediate value 30H
MOV DL, 40H         ; Load DL with immediate value 40H

; Task b: Copy contents of AL, BL, CL, DL into BH, CH, DH, AL
MOV BH, AL          ; Copy AL to BH
MOV CH, BL          ; Copy BL to CH
MOV DH, CL          ; Copy CL to DH
MOV AH, DL          ; Copy DL to AH (DL is part of DX)

; Task c: SWAP between AX and BX registers
XCHG AX, BX         ; Swap AX and BX

; Task d: Copy AX to memory location 0200h, then BX and CX to consecutive addresses
MOV [0200H], AX     ; Copy AX to memory location 0200H
MOV [0202H], BX     ; Copy BX to memory location 0202H
MOV [0204H], CX     ; Copy CX to memory location 0204H

; Task e: Copy DX to stack segment memory location 0100h, then 4433h and 2211h to consecutive addresses
MOV SS:[0100H], DX  ; Copy DX to stack segment memory location 0100H
MOV SS:[0102H], 4433H ; Copy 4433H to stack segment memory location 0102H
MOV SS:[0104H], 2211H ; Copy 2211H to stack segment memory location 0104H

ret     ; Return to the operating system (end of the program)




