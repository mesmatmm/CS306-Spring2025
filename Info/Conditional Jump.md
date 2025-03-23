

<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [Conditional Jump instructions (J)](#conditional-jump-instructions-j)
  - [Jcondition label](#jcondition-label)
  - [Conditional Jump instruction for the unsigned numbers:](#conditional-jump-instruction-for-the-unsigned-numbers)
  - [Conditional Jump instruction for the signed numbers:](#conditional-jump-instruction-for-the-signed-numbers)

<!-- /code_chunk_output -->


# Conditional Jump instructions (J)

- In the 8086 through the 80286 microprocessors, conditional jump instructions are always jump to any location within the current code segment.

## Jcondition label

    ; condition : depends on the result from  
    ; any arithmetic or logic operations (refers to status flags)  
    ; label : refers to code label  

- If the **condition** under test is **true**, a branch to the **label** associated with the conditional jump instruction is executed. If the **condition** is **false**, the next sequential step in the program is executed.

***

- Although the **CMP** instruction is the same for both unsigned and signed numbers, the **conditional jump instructions** used to make a decision for the **unsigned numbers** are different from the **signed numbers**.

- **Conditional jump instructions** which are used with **unsigned numbers** are **JA, JB, JAE, JBE, JE, and JNE**.

- **Conditional jump instructions** which are used with **signed numbers** are **JG, JL, JGE, JLE, JE, and JNE**.

***

## Conditional Jump instruction for the unsigned numbers:

| Conditional Jump instruction | Description                        | Flag condition       |
|------------------------------|------------------------------------|----------------------|
| JE, JZ                       | Jump if equal (zero)               | ZF = 1               |
| JNE, JNZ                     | Jump if not equal (not zero)       | ZF = 0               |
| JA, JNBE                     | Jump if above (not below or equal) | CF=0 and ZF=0        |
| JB, JNAE, JC                 | Jump if below (not above or equal/carry) | CF=1         |
| JAE, JNB, JNC                | Jump if above or equal (not below/not carry) | CF=0    |
| JBE, JNA                     | Jump if below or equal (not above) | CF=1 or ZF=1         |
| JPE, JP                      | Jump if parity even                | PF=1                 |
| JPO, JNP                     | Jump if parity odd (no parity)     | PF=0                 |

***

## Conditional Jump instruction for the signed numbers:

| Conditional Jump instruction | Description    | Flag condition    |
|---|---|---|
| JE, JZ    | Jump if equal (zero)    | ZF = 1    |
| JNE, JNZ    | Jump if not equal (not zero)    | ZF = 0    |
| JG, JNLE    | Jump if greater (not less or equal)    | SF=OF and ZF=0    |
| JL, JNGE    | Jump if less (not greater or equal)    | SF≠OF    |
| JGE, JNL    | Jump if greater or equal (not less)    | SF=OF    |
| JLE, JNG    | Jump if less or equal (not greater)    | SF≠OF or ZF=1    |
| JPE, JP    | Jump if parity even    | PF=1    |
| JPO, JNP    | Jump if parity odd (no parity)    | PF=0    |
| JO    | Jump if overflow    | OF=1    |
| JNO    | Jump if not overflow    | OF=0    |
| JS    | Jump if sign    | SF=1    |
| JNS    | Jump if not sign    | SF=0    |

***
