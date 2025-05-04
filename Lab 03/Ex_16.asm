org 100h  ; Start the program at memory location 100h (typical for .COM files)

; Define data
var1 db 15h  ; Define a byte variable `var1` with value 15h (21 in decimal)
var2 db 20h  ; Define a byte variable `var2` with value 20h (32 in decimal)
var3 db 10h  ; Define a byte variable `var3` with value 10h (16 in decimal)
result dw ?  ; Reserve a word (2 bytes) for storing the result

; Perform calculations
neg var1     ; Negate the value of `var1` (two's complement). 15h becomes -15h (or -21 in decimal)
mov al, var1 ; Move the negated value of `var1` into the AL register (8-bit)
add al, var2 ; Add the value of `var2` (20h) to AL. AL now contains (-15h + 20h) = 0Bh (11 in decimal)
mul var3     ; Multiply AL by `var3` (10h). The result is stored in AX (16-bit), since `mul` uses AL * operand.

; Store the result
mov result, ax ; Move the result of the multiplication (stored in AX) into the `result` variable

ret           ; Return from the program (end execution)