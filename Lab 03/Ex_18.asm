org 100h

var db 10h, 11h, 12h, 13h

; Using Direct-offset Addressing
mov al, var[0]      ; mov al, [var + 0]  
mov ah, var[1]      ; mov ah, [var + 1]
mov bl, var[2]      ; mov bl, [var + 2]
mov bh, var[3]      ; mov bh, [var + 3]

;   Using Index addressing
;   move si, 0
;   mov al, var[si]
;   inc si
;   mov ah, var[si]
;   inc si
;   mov bl, var[si]
;   inc si
;   mov bh, var[si]



ret