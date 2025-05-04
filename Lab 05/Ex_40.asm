
; File Name: .asm
; Date: Day-Month-2025
; Author: Mahmoud Esmat

org 100h              ; Set the origin address to 100h for the program

mov cx, 7             ; Initialize counter (CX) to 7 for 8 elements (0 to 7)
mov si, 0             ; Initialize source index (SI) to 0 to start from the first element
mov al, degrees[si]   ; Load the first element (degrees[0]) into AL as the initial minimum

L1:                   ; Start of the loop to find the minimum
   inc si             ; Increment SI to point to the next element
   cmp al, degrees[si]; Compare the current minimum (AL) with the next element
   JL L2             ; Jump to L2 if AL is less than degrees[si] (signed comparison)
   mov al, degrees[si]; Update AL with the new minimum if degrees[si] is smaller
L2:                   ; Label for the jump
Loop L1              ; Decrement CX and loop back to L1 if CX is not zero

mov min_degree, al    ; Store the final minimum value in min_degree

; Set up video mode to display the message at a specific location
mov ax, 0B800h        ; Load the video segment address (0B800h) into AX
mov es, ax            ; Move AX to ES (extra segment) for video memory
mov si, 0             ; Reset SI to 0 to index the MSG array
mov di, 320h          ; Set DI to 320h (160 characters * 2 bytes per character) for display position
mov cx, 19            ; Set CX to 19 for the length of the message 'Minimum is detected'

L3:                   ; Start of the loop to display the message
   mov al, MSG[si]    ; Load the next character of MSG into AL
   mov es:[di], al    ; Store the character at the video memory location (ES:DI)
   inc si             ; Increment SI to point to the next character
   add di, 2          ; Increment DI by 2 (skip attribute byte in video memory)
Loop L3              ; Decrement CX and loop back to L3 if CX is not zero

ret                  ; Return from the program

DEGREES db +25, -20, -10, -30, -13, -25, +22, +30 ; Define the signed byte array with 8 temperature degrees
MIN_DEGREE db ?        ; Reserve a byte for the minimum degree variable
MSG db 'Minimum is detected'   ; Define the message string (19 characters)