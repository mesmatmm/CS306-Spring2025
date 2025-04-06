;Compare.
;
;Algorithm:
;
;operand1 - operand2
;
;result is not stored anywhere, 
;flags are set (OF, SF, ZF, AF, PF, CF) according to result.
;
;Example:        

MOV AL, 5
MOV BL, 5
CMP AL, BL  ; AL = 5, ZF = 1 (so equal!)
RET