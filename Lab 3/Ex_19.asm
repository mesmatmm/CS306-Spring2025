org 100h

var dw 1010h, 2020h, 3030h
copy dw 3 dup(?)

; Using Direct Offset Addressing
mov ax, var[0]
mov copy[0], ax

mov ax, var[2]
mov copy[2], ax

mov ax, var[4]
mov copy[4], ax