ORG 100h       ; Set the program's origin address at 100h

MOV AL, VAR1   ; Load the first signed variable (VAR1) into register AL
MOV BL, VAR2   ; Load the second signed variable (VAR2) into register BL

CMP AL, BL     ; Compare AL with BL (signed comparison)
JG LARGER      ; If AL > BL (signed comparison), jump to LARGER label

; If AL is not greater than BL (i.e., AL <= BL)
MOV LOW, AL    ; Store AL (smaller value) in LOW
MOV HIGH, BL   ; Store BL (larger value) in HIGH
JMP STOP       ; Jump to STOP to exit the program

LARGER:        
MOV HIGH, AL   ; If AL > BL, store AL (larger value) in HIGH
MOV LOW, BL    ; Store BL (smaller value) in LOW

STOP:          
RET            ; Return from the program

VAR1 DB 7Fh    ; Define VAR1 with the value 7Fh (+127 in signed decimal)
VAR2 DB 80h    ; Define VAR2 with the value 80h (-128 in signed decimal)
LOW DB ?
HIGH DB ?