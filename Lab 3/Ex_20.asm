org 100h

var1 dw 2000h
var2 dw 3000h

mov ax, var1
xchg ax, var2
mov var1, ax

ret