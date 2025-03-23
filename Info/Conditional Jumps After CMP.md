In x86 assembly, comparison instructions are used to compare two operands and set flags accordingly. The choice of comparison instructions depends on whether the operands are **signed** or **unsigned**. Here are the most common comparison instructions:

### 1. **CMP (Compare)**
   - `CMP dest, src`  
   - Subtracts `src` from `dest` but **does not store the result**—only updates the CPU flags.
   - Used for both **signed** and **unsigned** comparisons.

### 2. **TEST (Bitwise AND)**
   - `TEST dest, src`  
   - Performs a bitwise AND between `dest` and `src` and updates the flags.
   - Typically used for checking if a value is zero or if certain bits are set.

---

### **Conditional Jumps After CMP**
Once `CMP` is used, conditional jumps can be used based on the signedness of operands.

#### **For Unsigned Comparisons**
- `JA`  (Jump if Above) → Equivalent to `>` (unsigned) → `CF=0` and `ZF=0`
- `JAE` (Jump if Above or Equal) → Equivalent to `>=` (unsigned) → `CF=0`
- `JB`  (Jump if Below) → Equivalent to `<` (unsigned) → `CF=1`
- `JBE` (Jump if Below or Equal) → Equivalent to `<=` (unsigned) → `CF=1 or ZF=1`

#### **For Signed Comparisons**
- `JG`  (Jump if Greater) → Equivalent to `>` (signed) → `ZF=0 and SF=OF`
- `JGE` (Jump if Greater or Equal) → Equivalent to `>=` (signed) → `SF=OF`
- `JL`  (Jump if Less) → Equivalent to `<` (signed) → `SF≠OF`
- `JLE` (Jump if Less or Equal) → Equivalent to `<=` (signed) → `ZF=1 or SF≠OF`

#### **For Equality Checks (Used in Both Signed and Unsigned Comparisons)**
- `JE`  (Jump if Equal) → `ZF=1`
- `JNE` (Jump if Not Equal) → `ZF=0`

---

### **Example**
#### **Unsigned Comparison (`JA, JB`)**
```assembly
mov eax, 10
cmp eax, 5
ja above_label  ; Jumps because 10 > 5 (unsigned)
```

#### **Signed Comparison (`JG, JL`)**
```assembly
mov eax, -10
cmp eax, 5
jl less_label   ; Jumps because -10 < 5 (signed)
```

Would you like more details on a specific scenario?