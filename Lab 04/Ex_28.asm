org 100h          ; Set origin for a DOS .COM program (starts at offset 100h)

lea si, data      ; Load effective address of 'data' array into SI register
mov cx, 16        ; Set loop counter to 16 (processing 16 elements)
mov bl, 00h       ; Initialize bl to 0 (starting value for array elements)
mov al, 00h       ; Initialize al to 0 (used to store sum)

ArrayData:
    mov [si], bl      ; Store the value of bl into the array at SI
    add al, [si]      ; Add the value at SI to al (accumulate sum)
    inc si            ; Move to the next array element
loop ArrayData    ; Decrement CX and repeat if CX != 0

mov sum, al       ; Store total sum into 'sum' variable
mov dl, 16        ; Load divisor (16) into dl for average calculation
div dl            ; Divide AX by 16, quotient in AL (remainder in AH)
mov avg, ax       ; Store the calculated average in 'avg'

ret               ; Return control to the operating system

data db 16 dup(?) ; Declare an array of 16 bytes (uninitialized)
sum db ?          ; Reserve a byte for storing sum
avg dw ?          ; Reserve a word (2 bytes) for storing average
