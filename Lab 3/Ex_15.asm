org 100h  ; Start the program at memory location 100h (typical for .COM files)

; Define data
marks db 60, 80, 90  ; Define an array of marks with values 60, 80, and 90
sum dw ?             ; Reserve a word (2 bytes) for storing the sum of marks
avg dw ?             ; Reserve a word (2 bytes) for storing the average of marks

; Calculate the sum of marks
mov al, marks[0]     ; Load the first mark (60) into AL (8-bit register)
add al, marks[1]     ; Add the second mark (80) to AL
add al, marks[2]     ; Add the third mark (90) to AL
mov sum, ax          ; Store the result (sum) in the 'sum' variable (AX is 16-bit, so it includes AL))

; Calculate the average of marks
mov bl, 3            ; Load the divisor (number of marks, which is 3) into BL
div bl               ; Divide AX (sum) by BL (3). The quotient (average) is stored in AL
mov avg, ax          ; Store the result (average) in the 'avg' variable

; Load effective addresses of variables
lea si, sum          ; Load the address of 'sum' into SI (equivalent to 'mov si, offset sum')
lea di, avg          ; Load the address of 'avg' into DI (equivalent to 'mov di, offset avg')

ret                  ; Return from the program (end execution)