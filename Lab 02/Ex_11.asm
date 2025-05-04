
; File Name: .asm
; Date: 11-Feb-2025
; Author: Mahmoud Esmat

org 100h

factorial5 DW ?  ; Variable to store the factorial of 5

; Initialize AX with 1 (to store the result)
MOV AX, 1

; Calculate 5! = 5 * 4 * 3 * 2 * 1
MOV CX, 5        ; Load 5 into CX
MUL CX           ; AX = AX * 5 (1 * 5 = 5)

MOV CX, 4        ; Load 4 into CX
MUL CX           ; AX = AX * 4 (5 * 4 = 20)

MOV CX, 3        ; Load 3 into CX
MUL CX           ; AX = AX * 3 (20 * 3 = 60)

MOV CX, 2        ; Load 2 into CX
MUL CX           ; AX = AX * 2 (60 * 2 = 120)

MOV CX, 1        ; Load 1 into CX
MUL CX           ; AX = AX * 1 (120 * 1 = 120)

; Save the result into factorial5 variable
MOV factorial5, AX

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; Initialize the number for which factorial is to be calculated
;MOV CX, 5        ; Load 5 into CX (counter)
;MOV AX, 1        ; Initialize AX with 1 (to store the result)
;
;; Calculate factorial
;FACTORIAL_LOOP:
;    MUL CX       ; AX = AX * CX
;    LOOP FACTORIAL_LOOP ; Decrement CX and loop until CX is 0
;
;; Save the result into factorial5 variable
;MOV factorial5, AX

ret




