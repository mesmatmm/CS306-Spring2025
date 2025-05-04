;cmp
;FLags; ZF, CF, SF, OF

; conditional JUMP
;unsigend: ja, jb, je, jne, jae, jbe
; signed: jg, jl, je, jne, jge, jle 
; adc: add with carry
;  jc: jump if carry
; jnc: jump not carry
; printn 'message'

; putc 'A'

; Display using video mode

include 'emu8086.inc'
org 100h

;mov al, -10
;mov bl, 5
;
;cmp al, bl  ; al - bl
;jg L ; al > bl
;    print 'AL is less than or equal to BL'
;jmp exit
;L:
;   print 'AL is greater than BL'
;    
;exit: 
;ret


;mov al, array[0]
;mov bl, array[1]
;cmp al, bl
;ja L   ; al > bl
;mov max, bl
;mov min, al 
;jmp exit
;L:
;    mov max, al
;    mov min, bl
;exit:
;ret
;array db 30, 70
;min db ?
;max db ? 

mov al, 127
mov bl, 1

add al, bl 
;jnc L  ; jnc = jump if not carry
;    adc ah, 0 ; ah = ah + 0 + CF  ; adc = add with carry
;L:
;mov sum, ax

ret 
sum dw ?


;mov al, 0 
;mov cx, 5
;mov si, 0
;start:
;     mov bl, array[si]
;     add al, bl
;    ;jnc L
;    adc ah, 0 ; ah = ah + 0 + CF 
;    inc si  
;loop start
;
;mov sum, ax
;
;printn 'ALL is done'
;
;ret 
;array db 255, 20 , 10, 255, 20
;sum dw ?    


;array 10, 5, 7, 3, 41, 9 find max, min in one Loop
;array -10, +5, +17, -3, -41, +9 find max, min in one Loop 

; given 2 Arrays 1 3 and 4 5 ; required to merge into one sorted array