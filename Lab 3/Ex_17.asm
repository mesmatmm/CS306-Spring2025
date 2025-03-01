org 100h  ; Start the program at memory address 100h (typical for .COM files in DOS)

marks db 10, 20, 30 ; Define an array of marks with 3 values
copy db 2 dup(?)    ; Reserve space for 2 bytes to store a copy of the first two marks

; Using Indirect Addressing to copy values from 'marks' to 'copy'

lea si, marks   ; Load the address of 'marks' into the SI register (Source Index)
lea di, copy    ; Load the address of 'copy' into the DI register (Destination Index)


mov al, [si]    ; Copy the first value from 'marks' (pointed to by SI) to AL register
mov [di], al    ; Store the value in AL into the first position of 'copy' (pointed to by DI)


inc si  ; Increment SI to point to the next value in 'marks'
inc di  ; Increment DI to point to the next position in 'copy'

mov al, [si]    ; Copy the second value from 'marks' (pointed to by SI) to AL register
mov [di], al    ; Store the value in AL into the second position of 'copy' (pointed to by DI)


ret ; End of the program

; Using Direct offset Addressing
; mov al, marks[0]     ; move al, [marks]
; mov copy[0], al      ; mov [copy], al

; mov al, marks[1]     ; move al, [marks+1]
; mov copy[1], al      ; mov [copy+1], al

; Using Index Addressing
; mov si, 0
; mov al, marks[si]
; mov copy[si], ai
; inc si
; mov al, marks[si]
; mov copy[si], ai