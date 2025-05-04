org 100h            ; Set origin for a DOS .COM program (starts at offset 100h)

mov cx, 41         ; Set loop counter to 41 (length of the string)
mov si, 0          ; Initialize index SI to 0

CopyData:
    mov al, source[si]   ; Load the character from SOURCE at index SI into AL
    mov target[si], al   ; Store the character from AL into TARGET at the same index
    inc si               ; Increment SI to move to the next character
loop CopyData            ; Decrement CX and repeat if CX != 0

ret                     ; Return control to the operating system

SOURCE db 'Assembly language is a low level language'  ; Define the source string
TARGET db 41 dup(?)     ; Reserve 41 bytes for TARGET (uninitialized)



;lea si, source
;lea di, target
;mov cx, 41
;Exchange:
;    mov al, [si]
;    mov [di], al
;    inc si
;    inc di
;loop exchange
