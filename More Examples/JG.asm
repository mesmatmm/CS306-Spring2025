
; File Name: .asm
; Date: 07-March-2025
; Author: Mahmoud Esmat

; Short Jump if first operand is Greater then
; second operand (as set by CMP instruction). Signed.

;Algorithm:
;
;if (ZF = 0) and (SF = OF) then jump
;Example:
include 'emu8086.inc'
ORG 100h
MOV AL, 5
CMP AL, -5
JG  label1
PRINT 'AL is not greater -5.'
JMP exit
label1:
   PRINT 'AL is greater -5.'
exit:
   RET




