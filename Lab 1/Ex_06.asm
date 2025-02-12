org 100h        ; Set the origin to 100h (typical for COM programs in DOS)

; Task a: Initialize AL and DL registers
MOV AL, 38H         ; Load AL with immediate value 38H
MOV DL, 0E0H        ; Load DL with immediate value 0E0H

; Task b: Set the rightmost 5-bits of DL without changing the remaining bits
OR DL, 00011111B          ; Set the rightmost 5 bits of DL (1FH = 00011111B)

; Task c: Set the leftmost 3-bits of AL, clear bits 2, 3, and 4 of AL, and invert the rightmost 2 bits of AL
OR AL, 11100000B         ; Set the leftmost 3 bits of AL (E0H = 11100000B)
AND AL, 11100011B        ; Clear bits 2, 3, and 4 of AL (E3H = 11100011B)
XOR AL, 00000011B         ; Invert the rightmost 2 bits of AL (03H = 00000011B)


ret             ; Return to the operating system (end of the program)
