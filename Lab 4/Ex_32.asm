ORG 100h       ; Set the program's origin address at 100h

MOV AL, VAR1   ; Load the first variable (VAR1) into register AL
MOV BL, VAR2   ; Load the second variable (VAR2) into register BL

CMP AL, BL     ; Compare AL with BL
JA LARGER      ; If AL > BL (unsigned comparison), jump to LARGER label

MOV LOW, AL    ; If AL <= BL, store AL (smaller value) in LOW
MOV HIGH, BL   ; Store BL (larger value) in HIGH
JMP STOP       ; Jump to STOP to exit the program

LARGER:        
MOV HIGH, AL   ; If AL > BL, store AL (larger value) in HIGH
MOV LOW, BL    ; Store BL (smaller value) in LOW

STOP:          
RET            ; Return from the program

VAR1 DB 7Fh    ; Define VAR1 with the value 7Fh (127 in decimal)
VAR2 DB 80h    ; Define VAR2 with the value 80h (128 in decimal)
LOW DB ?
HIGH DB ?