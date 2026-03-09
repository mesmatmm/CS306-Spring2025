## Lab 2 - Exercises - Assembly - Emu8086

###  Table of Contents
- [Ex_07](#ex_07)
- [Ex_08](#ex_08)
- [Ex_09](#ex_09)
- [Ex_10](#ex_10)
- [Ex_11](#ex_11)

###  **Ex_07**
Using emu8086 program, write a program in Assembly language that **performs** the following tasks, showing the contents of the affected **registers** and flags:

A) **Initialize** the **AX**, **BX**, and **DI** **registers** with the immediate values 1020H, 3040H, and 0200H respectively.

B) One's complement the low byte of **AX** **register**.

C) Two's complement the high byte of the **BX** **register**.

D) **Save** the high byte of **AX** and the low byte of **BX** at the data segment memory locations addressed by **DI** respectively.

###  **Ex_08**
Write a program that **performs** the following:

A) **Initialize** the **AX** and **BX** **registers** by 100h and 200h respectively.

B) **Add** 50h to the contents of **AX** **register** then increase the result by one. **Subtract** 50h from the contents of **BX** **register** then decrease the result by one. Finally, **swap** the data in the previous **registers**.

C) **Save** a data of 300h and 400h into the data segment memory locations addressed by 600h and its consecutive addresses respectively. **Add** the contents of the previous memory locations and **save** the result into the **CX** **register**.

D) Run the program and show the affected **registers**, flags and memory locations.

### **Ex_09**
Write a program to **perform** the following tasks, showing the contents of **registers**, memory locations and the affected flags:

A) **Initialize** the **AX** **register** by FF00h, **set** the rightmost 8 bits of **AX**, **clear** bits 8 and 9 of **AX** and **invert** the leftmost 6 bits of **AX** with the result stored in **BX** **register**.

B) **Initialize** the low order byte of the **CX** **register** by EFh as well as **save** its one's complement at the high order byte of the **CX** **register**.

C) **Initialize** the low order byte of the **DX** **register** by EFh as well as **save** its 2's complement at the high order byte of the **DX** **register**.

### **Ex_10**
Write an assembly program that calculates a rectangle area, which has 7h and 3h dimensions. Also, calculates the half of the rectangle area. **Save** the results into area and half_area variables.

### **Ex_11**
Write a program that calculates the factorial of 5 (5!). **Save** the result into factorial5 variable.