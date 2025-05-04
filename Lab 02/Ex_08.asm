org 100h        ; Set the origin to 100h (typical for COM programs in DOS)

; A) Initialize AX and BX registers
MOV AX, 100H
MOV BX, 200H

; B) Operations on AX and BX
ADD AX, 50H      ; Add 50h to AX
INC AX           ; Increase AX by one
SUB BX, 50H      ; Subtract 50h from BX
DEC BX           ; Decrease BX by one
XCHG AX, BX      ; Swap AX and BX

; C) Save data into memory and perform addition
MOV [600H], 300H  ; Save 300h at address 600h
MOV [602H], 400H  ; Save 400h at address 602h (consecutive address)
MOV CX, [600H]    ; Load 300h into CX
ADD CX, [602H]    ; Add 400h to CX (result in CX)

ret             ; Return to the operating system (end of the program)