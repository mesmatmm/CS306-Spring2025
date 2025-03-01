; Ex_23: What is the final values of AL and BL registers in the following Assembly program?

ORG 100h  
MOV AL, 4h  
MOV BL, 8h  
MOV CX, 3  
L1:  
ADD AL, 2h  
INC BL  
Loop L1  
RET  





































;Solution:  
;AL = 0Ah  
;BL = 0Bh