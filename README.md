# CS306 : Operating Systems - Spring 2025

---

<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->
### Table of Contents
- [CS306 : Operating Systems - Spring 2025](#cs306--operating-systems---spring-2025)
    - [Table of Contents](#table-of-contents)
- [Lab Outline](#lab-outline)
  - [Assembly X8086](#assembly-x8086)
    - [Labs 1 and 2](#labs-1-and-2)
    - [Lab 3](#lab-3)
    - [Lab 4](#lab-4)
    - [Lab 5](#lab-5)
  - [Threads using C](#threads-using-c)
    - [Lab 6](#lab-6)
    - [Lab 7](#lab-7)
    - [Lab 8](#lab-8)
    - [Lab 9 (Practical Exam)](#lab-9-practical-exam)
  - [Threads using JAVA](#threads-using-java)
    - [Lab 10](#lab-10)
    - [Lab 11 (Self-Study)](#lab-11-self-study)
    - [Lab 12 (Practical Exam)](#lab-12-practical-exam)

<!-- /code_chunk_output -->

***

# Lab Outline

## Assembly X8086

- We're using Emu8086 to simulate the execution of the assembly program.
- You can download Emu8086 from here
 [Emu8086](https://archive.org/details/Emu8086V408r11)

### Labs 1 and 2

- Basic Structure for Assembly X8086 program.
- Basic instructions: **MOV**, **ADD**, **SUB**
- Register VS Memory
- Basic Registers:
  - **AX (AH + AL)**
  - **BX (BH + BL)**
  - **CX (CH + CL)**
  - **DX (DH + DL)**
- How to set/initialize the registers with immediate value (hex, binary, or decimal)
- Access different memory locations:
  - Data segment memory location.
  - Stack segment memory location.
  - Extra data segment memory location.
- How to set bits using **OR**
- How to clear bits using **AND**
- How to invert bits using **XOR**
- How to find 1's complement: using **NOT**
- How to find 2's complement: using **NEG**
- Swapping two operands using **XCHG**
- More instructions: **MUL** and **DIV**
- Define variables (initialized or not):
  - **db** (define byte = 8 bits).
  - **dw** (define word = 2 bytes = 16 bits).

***

### Lab 3

- how to define an array (initialized or not):
  - array of bytes
  - array of words
- How to access the array elements:
  - using **direct addressing** (or Using **direct-offset Addressing**).
  - using **index addressing**.
  - using **indirect addressing** by (**LEA** or **OFFSET**).
- How to define **Label**.
- Unconditional control instruction: **JUMP**.
- **Loop**
- Nested Loops.

***

### Lab 4

- More exercises on using **Loop** and arrays.
- More instrustions:
  - **CMP**
  - **JA**
  - **JG**
  - **CBW**
  - **CWD**
- how different **FLAGS** are affected by some instructions:
  - **ZP**: Zero Flag.
  - **CF**: Carry Flag.
  - **OF**: Overflow Flag.

***

### Lab 5

- More difficult exercises covering **Loop**,  arrays, and conditional jump control instructions for unsigned and signed.
- **PRINT** and **PRINTN**
- More instrustions:
  - **ADC**: Add with Carry
  - **JC**: if CF = 1 then jump
  - **JNC**: if CF = 0 then jump
- FYI:
  - Printing using **Video Mode**.
  - **PUTC**

***
***

## Threads using C

### Lab 6

- Processes and Threads: Definitions and Differences
- Threads vs Processes
- Need for Multithreading
- Features of Using Threads
- Types of Threads
- Thread Libraries
- Creating and Assigning Work to Threads
- Compile and Run C Files with Threads
- Pointers & References.

### Lab 7

- Struct Usage in C
- How to use struct to pass multiple values to the thread function
- Retrieve value from Thread function
- Passing & Retrieving Multiple Values via Struct
- Synchronization between Threads
- Race condition
- Deadlocks and Livelocks.
- Common Synchronization Tools
  - **mutex (Mutual Exclusion)**
  - **semaphore**

### Lab 8

- Case Studies
  - **Producer-Consumer** Problem with Mutex and Condition Variables
  - **Producer-Consumer** Problem with Semaphore
  - **Readers-Writers** Problem
  - **Dining-Philosophers** Problem

### Lab 9 (Practical Exam)

***
***

## Threads using JAVA

### Lab 10

- Creating threads using **Thread** class
- Creating threads using **Runnable** interface
- Synchronizartion tools:
  - **volatile** keyword
  - **synchronized** keyword
    - **syncronized** method
    - **synchronized** block
  - locks
  - mutex
  - semaphores
  - condition variables
- Creating Thread Pool using **ExecutorService**
- Lambda expresssion
- Using **Future** to wait for the returned value from a thread


### Lab 11 (Self-Study)

1. **Thread Priorities (Ex12)**  
   - Setting thread priorities (`MIN_PRIORITY`, `NORM_PRIORITY`, `MAX_PRIORITY`).  
   - OS-dependent scheduling behavior (no strict guarantees).  

2. **Wait-Notify Mechanism (Ex13)**  
   - Basic thread coordination using `wait()` and `notify()`.  
   - Guarded blocks with `synchronized` and loop checks for spurious wakeups.  

3. **Producer-Consumer Pattern (Ex14)**  
   - Synchronized buffer with `wait()`/`notifyAll()`.  
   - Handles empty/full states to prevent race conditions.  

4. **ReadWriteLock (Ex15)**  
   - `ReentrantReadWriteLock` for concurrent reads and exclusive writes.  
   - Improves performance in read-heavy scenarios.  

5. **CountDownLatch (Ex16)**  
   - One-time synchronization: main thread waits for worker threads.  
   - `countDown()` decrements; `await()` blocks until zero.  

6. **CyclicBarrier (Ex17)**  
   - Reusable barrier for thread synchronization at fixed points.  
   - Optional barrier action triggers when all threads arrive.  

7. **ThreadLocal (Ex18, Ex19)**  
   - Thread-local variables for isolated per-thread storage.  
   - Two approaches: shared `Map` (Ex18) vs. `Future`/`ExecutorService` (Ex19).  

8. **Atomic Operations (Ex20)**  
   - `AtomicInteger` for lock-free, thread-safe counters.  
   - Methods like `incrementAndGet()` avoid race conditions.  

### Lab 12 (Practical Exam)
  - Tuesday: May 13, 2025

***
***
