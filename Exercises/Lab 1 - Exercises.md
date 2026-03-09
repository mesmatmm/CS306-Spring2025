## Lab 1 - Exercises - Assembly - Emu8086

### Table of Contents
1. [Ex_01](#ex_1)
2. [Ex_02](#ex_2)
3. [Ex_03](#ex_3)
4. [Ex_04](#ex_4)
5. [Ex_05](#ex_05)
6. [Ex_06](#ex_06)

---

### **Ex_1**
Using emu8086 program, write a program in Assembly language that performs the following tasks, showing the contents of the affected registers, memory locations and flags:

A) Initialize **AX** and **SI** registers with the immediate value **1520H** and **0300H** respectively.

B) Save the immediate value **3040H** at the data segment memory location addressed by **SI**.

C) **Add** the word contents at the data segment memory location addressed by **SI** to **AX** with the sum stored at the **AX** register.

---

### **Ex_2**
Using emu8086 program, write a program in Assembly language that performs the following tasks, showing the contents of the affected registers and flags:

A) Initialize **AX** and **DX** registers with the immediate values **1234h** and **5678h** respectively.

B) **Subtract** the word content of **AX** register from the word content of **DX** register with the difference stored in the **DX** register.

---

### **Ex_3**
Using emu8086 program, write a program in Assembly language that performs the following tasks, showing the affected registers and memory locations:

A) Initialize **AL**, **BL**, **CL** and **DL** registers with the immediate data **10h**, **20h**, **30h** and **40h** respectively.

B) **Copy** the contents of **AL**, **BL**, **CL** and **DL** registers into **BH**, **CH**, **DH** and **AH** registers respectively.

C) **SWAP** between the contents of **AX** and **BX** registers.

D) **Copy** the content of **AX** register into the data segment memory location addressed by **0200h** then **copy** the contents of **BX** and **CX** registers at the consecutive offset addresses.

E) **Copy** the content of **DX** register into the stack segment memory location addressed by **0100h** then **Copy** the immediate data **4433h** and **2211h** at the consecutive offset addresses.

---

### **Ex_4**
Using emu8086 program, write a program in Assembly language that performs the following tasks, showing the affected registers and memory locations:

A) **Copy** the string data 'NO' into **AX** register. Initialize the source index register (**SI**) with the initial value **0200H** and the base pointer register (**BP**) with initial value **0100H** then **copy** the contents of **AX** register into the stack segment memory locations addressed by **SI+BP+20H**.

B) **Initialize** the destination index register (**DI**) with initial value **0300H** then **copy** the string data 'HELLO' into the extra data segment memory locations addressed by **DI+100H**.

---

### **Ex_05**
Using emu8086 program, write a program in Assembly language that performs the following tasks, showing the affected registers and memory locations:

A) **Initialize** the **AL** and **SI** registers with **33h** and **0300h** respectively.

B) **Copy** the data segment memory location addressed by **SI** with **55h**. Then, **swap** between **AL** and the data at the data segment memory.

---

### **Ex_06**
Using emu8086 program, write a program in Assembly language that performs the following tasks, showing the contents of the affected registers and flags:

A) **Initialize** the **AL** and **DL** registers with the immediate values **38H** and **0E0H** respectively.

B) **Set** the rightmost 5-bits of **DL** without changing the remaining bits of **DL**.

C) **Set** the leftmost 3-bits of **AL**, **clears** bits 2, 3, and 4 of **AL**, and **inverts** the rightmost 2 bits of **AL**.