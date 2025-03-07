
; File Name: .asm
; Date: 07-March-2025
; Author: Mahmoud Esmat

;Short Jump if first operand is Above second operand
; (as set by CMP instruction). Unsigned.
;
;Algorithm:
;
;if (CF = 0) and (ZF = 0) then jump
; Example:  

include 'emu8086.inc'
ORG 100h
MOV AL, 250
CMP AL, 5
JA label1
PRINT 'AL is not above 5'
JMP exit
label1:
   PRINT 'AL is above 5'
exit:
   RET




