org 1010h

var dw 1020h
copy dw ?

;   using indirect addressing

mov si, offset var       ; lea si, var
mov di, offset copy      ; lea di, copy

mov ax, [si]
mov [di], ax

ret