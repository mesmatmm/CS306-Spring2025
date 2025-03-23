
## Comparison of the unsigned and signed numbers:
***

- **CMP instruction** changes the flag bits **CF, AF, SF, PF, ZF, and OF** according to the comparison result.

**Comparison of the unsigned numbers:**

CF and ZF are used to indicate the comparison result of the unsigned operands.

| Comparison results       | Flags               |
|--------------------------|---------------------|
| Destination > source     | CF=0 and ZF=0      |
| Destination < source     | CF=1               |
| Destination = source     | ZF=1               |

***

**Comparison of the signed numbers:**
SF, OF, and ZF are used to indicate the comparison result of the signed operands.

| Comparison results       | Flags               |
|--------------------------|---------------------|
| Destination > source     | SF=OF and ZF=0      |
| Destination < source     | SF ≠ OF             |
| Destination = source     | ZF=1                |

***

**Example:**  
MOV AX, 40  
CMP AX, 30 ; Result = 10, SF = 0, OF = 0, ZF = 0  

**Example:**  
MOV AX, 10  
CMP AX, 15 ; Result = -5, SF = 1, OF = 0  

**Example:**  
MOV AX, 5  
CMP AX, 5 ; Result = 0, ZF = 1

***

**Example:**  
MOV AX, 25  
CMP AX, 0 ; Result = 25, ZF = 0, CF = 0  

**Example:**  
MOV AX, 10  
CMP AX, 15 ; Result = -5, CF = 1  

**Example:**  
MOV AX, 5  
CMP AX, 5 ; Result = 0, ZF = 1

***

**Example:** For each of the following Assembly instructions, show the results of the Compare instructions, SF, ZF, CF, and OF flags.

MOV AL, 12    ; 12 and 10 are unsigned numbers (12 > 10)  
CMP AL, 10    ; result = 2, CF = 0, ZF = 0  

MOV AL, 0     ; 0 and 2 are unsigned numbers (0 < 2)  
CMP AL, 2     ; result = -2, CF = 1

***

**Example:** For each of the following signed arithmetic instructions, show the values of the destination operand, SF, ZF, and OF flags.

```
MOV AL, 127    ; AL = +127 = 7Fh  
ADD AL, 1      ; AL = -128 = 80h, SF = 1, ZF = 0, OF = 1  

MOV AL, 80h    ; AL = 80h = -128  
ADD AL, 0FEh   ; AL = 7Eh = +126, SF = 0, ZF = 0, OF = 1  

MOV AL, 03h    ; AL = 03h = +3  
SUB AL, 04h    ; AL = -1 = FFh, SF = 1, ZF = 0, OF = 0, SF ≠ OF (destination < source)  

MOV AL, 03h    ; AL = +3  
SUB AL, 01h    ; AL = +2 = 02h, SF = 0, ZF = 0, OF = 0, SF = OF (destination > source)  

MOV AL, 5      ; AL = +5 = 05h  
SUB AL, 5      ; AL = +0 = 00h, SF = 0, ZF = 1, OF = 0 (destination = source)

```

***