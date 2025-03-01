; Ex_22: Find the final values of AX and BX registers in the following Assembly program?

Org 100h  
MOV AX, 5  
MOV BX, 2  
JMP S1  
Back: INC AX  
JMP S2  
S1: SUB AX, BX  
JMP BACK  
S2: DEC BX
ret





































;Solution:
;AX = 0004h
;BX = 0001h
