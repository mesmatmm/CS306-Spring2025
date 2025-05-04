; Ex_25: What is the final values of AL and BL registers in the following program?

ORG 100h  
MOV AX, 0  
MOV BX, 0  
MOV CX, COUNT ;set outer loop count  
L1: 
    INC BL    ;BL = BL + 1  
    MOV COUNT, CX    ;save outer loop count  
    MOV CX, 2    ;set inner loop count  
        L2: 
            INC AL    ;AL = AL + 1  
            LOOP L2    ;repeat the inner loop  
    MOV CX, COUNT ;restore outer loop count  
LOOP L1    ;repeat the outer loop  
RET  
COUNT DW 5 











































; Solution:  
;   AL = 0Ah  
;   BL = 05h  