
; File Name: Ex_30.asm
; Date: 03-March-2025
; Author: Mahmoud Esmat

org 100h            ; Set the origin for a DOS .COM program (starts at offset 100h)  

; Initialize pointers to the arrays  
lea si, Edata       ; Load address of EDATA into SI (for even numbers)  
lea di, Odata       ; Load address of ODATA into DI (for odd numbers)  

mov cx, 50         ; Set loop counter to 50 (for 50 even and 50 odd numbers)  
mov bl, 00h        ; Initialize BL with 0 (starting even number)  
mov bh, 01h        ; Initialize BH with 1 (starting odd number)  
mov ax, 0000h      ; AX will store the sum of even numbers  
mov dx, 0000h      ; DX will store the sum of odd numbers  

OddEven:  
    mov [si], bl   ; Store even number in EDATA  
    mov [di], bh   ; Store odd number in ODATA  

    add bl, 2      ; Increment even number by 2  
    add bh, 2      ; Increment odd number by 2  

    add ax, [si]   ; Add even number to AX (sum of even numbers)  
    add dx, [di]   ; Add odd number to DX (sum of odd numbers)  

    add si, 2      ; Move to the next word in EDATA  
    add di, 2      ; Move to the next word in ODATA  

loop OddEven       ; Repeat for 50 numbers  

mov sume, ax       ; Store sum of even numbers in SUME  
mov sumo, dx       ; Store sum of odd numbers in SUMO  

mov bl, 50         ; Load 50 into BL for division  

div bl             ; Divide AX by 50 to calculate average of even numbers  
mov avgeq, al      ; Store quotient (integer part) in AVGEQ  
mov avger, ah      ; Store remainder in AVGER  

mov ax, sumo       ; Load sum of odd numbers into AX  
div bl             ; Divide AX by 50 to calculate average of odd numbers  
mov avgoq, al      ; Store quotient (integer part) in AVGOQ  
mov avgor, ah      ; Store remainder in AVGOR  

; Exchange elements of EDATA and ODATA  
mov cx, 50         ; Set loop counter to 50  
mov si, 0          ; Reset SI index to 0  

Exchange:  
    mov ax, edata[si]  ; Load value from EDATA  
    xchg ax, odata[si] ; Exchange it with value in ODATA  
    mov edata[si], ax  ; Store exchanged value back in EDATA  

    add si, 2          ; Move to the next word  
loop Exchange         ; Repeat for 50 numbers  

ret                  ; Return control to OS  

; Data section  
Edata dw 50 dup(?)   ; Reserve space for 50 even numbers  
Odata dw 50 dup(?)   ; Reserve space for 50 odd numbers  
sume dw ?            ; Variable to store sum of even numbers  
sumo dw ?            ; Variable to store sum of odd numbers  
avgeq db ?           ; Quotient of even numbers average  
avgoq db ?           ; Quotient of odd numbers average  
avger db ?           ; Remainder of even numbers average  
avgor db ?           ; Remainder of odd numbers average  




