# CS306 : Operating Systems - Spring 2025

---

<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->
## Table of Contents

- [Lab Outline](#lab-outline)
  - [Assembly X8086](#assembly-x8086)
    - [Labs 1 and 2](#labs-1-and-2--lab-01--lab-02)
    - [Lab 3](#lab-3--lab-03)
    - [Lab 4](#lab-4--lab-04)
    - [Lab 5](#lab-5--lab-05)
  - [Threads using C](#threads-using-c)
    - [Lab 6](#lab-6--lab-06)
    - [Lab 7](#lab-7--lab-07)
    - [Lab 8](#lab-8--lab-08)
    - [Lab 9 (Practical Exam)](#lab-9-practical-exam)
  - [Threads using JAVA](#threads-using-java)
    - [Lab 10](#lab-10--lab-10)
    - [Lab 11 (Self-Study)](#lab-11-self-study--lab-11)
    - [Lab 12 (Practical Exam)](#lab-12-practical-exam)
  - [Course Info](#course-info)

<!-- /code_chunk_output -->

***

## Lab Summary

This repository covers the lab sessions for CS306 Operating Systems, structured into three main tracks. The course begins with low-level **x86 Assembly** programming using Emu8086, covering registers, memory, control flow, arrays, and arithmetic instructions. It then transitions to **multithreading in C** using POSIX threads (pthreads), exploring thread creation, synchronization primitives (mutex, semaphore, condition variables), and classic concurrency problems. Finally, the course covers **multithreading in Java**, introducing the Thread API, Runnable interface, synchronization tools, thread pools, and concurrent utilities from `java.util.concurrent`. The objective is to build a solid understanding of concurrency, synchronization, and low-level system programming from both hardware and software perspectives.

***

# Lab Outline

## Assembly X8086

- We're using Emu8086 to simulate the execution of the assembly program.
- You can download Emu8086 from here
 [Emu8086](https://archive.org/details/Emu8086V408r11)

### Labs 1 and 2 — [Lab 01/](Lab%2001/) | [Lab 02/](Lab%2002/)

> Exercises: [Lab 1 - Exercises.md](Exercises/Lab%201%20-%20Exercises.md) | [Lab 2 - Exercises.md](Exercises/Lab%202%20-%20Exercises.md)

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

| File | Description |
| --- | --- |
| [Ex_01.asm](Lab%2001/Ex_01.asm) | Basic MOV, ADD, SUB |
| [Ex_02.asm](Lab%2001/Ex_02.asm) | Register operations |
| [Ex_03.asm](Lab%2001/Ex_03.asm) | Memory segments |
| [Ex_04.asm](Lab%2001/Ex_04.asm) | Bitwise: OR, AND, XOR |
| [Ex_05.asm](Lab%2001/Ex_05.asm) | NOT, NEG, XCHG |
| [Ex_06.asm](Lab%2001/Ex_06.asm) | MUL and DIV |
| [Ex_07.asm](Lab%2002/Ex_07.asm) | Variables (db, dw) |
| [Ex_08.asm](Lab%2002/Ex_08.asm) | Memory and registers |
| [Ex_09.asm](Lab%2002/Ex_09.asm) | Mixed instructions |
| [Ex_10.asm](Lab%2002/Ex_10.asm) | Mixed instructions |
| [Ex_11.asm](Lab%2002/Ex_11.asm) | Mixed instructions |

***

### Lab 3 — [Lab 03/](Lab%2003/)

> Exercises: [Lab 3 - Exercises.md](Exercises/Lab%203%20-%20Exercises.md)

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

| File | Description |
| --- | --- |
| [Ex_12.asm](Lab%2003/Ex_12.asm) | Array definition and access |
| [Ex_13.asm](Lab%2003/Ex_13.asm) | Direct addressing |
| [Ex_14.asm](Lab%2003/Ex_14.asm) | Index addressing |
| [Ex_15.asm](Lab%2003/Ex_15.asm) | Indirect addressing (LEA/OFFSET) |
| [Ex_16.asm](Lab%2003/Ex_16.asm) | Labels and JMP |
| [Ex_17.asm](Lab%2003/Ex_17.asm) | Loop |
| [Ex_18.asm](Lab%2003/Ex_18.asm) | Loop |
| [Ex_19.asm](Lab%2003/Ex_19.asm) | Loop |
| [Ex_20.asm](Lab%2003/Ex_20.asm) | Nested Loops |
| [Ex_21.asm](Lab%2003/Ex_21.asm) | Nested Loops |
| [Ex_22.asm](Lab%2003/Ex_22.asm) | Array + Loop |
| [Ex_23.asm](Lab%2003/Ex_23.asm) | Array + Loop |
| [Ex_24.asm](Lab%2003/Ex_24.asm) | Array + Loop |
| [Ex_25.asm](Lab%2003/Ex_25.asm) | Array + Loop |
| [Ex_26.asm](Lab%2003/Ex_26.asm) | Array + Loop |
| [Ex_27.asm](Lab%2003/Ex_27.asm) | Array + Loop |

***

### Lab 4 — [Lab 04/](Lab%2004/)

> Exercises: [Lab 4 - Exercises.md](Exercises/Lab%204%20-%20Exercises.md)

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

| File | Description |
| --- | --- |
| [Ex_28.asm](Lab%2004/Ex_28.asm) | CMP and conditional jumps |
| [Ex_29.asm](Lab%2004/Ex_29.asm) | JA, JG usage |
| [Ex_30.asm](Lab%2004/Ex_30.asm) | CBW, CWD |
| [Ex_31.asm](Lab%2004/Ex_31.asm) | Flags: ZF, CF, OF |
| [Ex_32.asm](Lab%2004/Ex_32.asm) | Loop + arrays + CMP |
| [Ex_33.asm](Lab%2004/Ex_33.asm) | Loop + arrays + CMP |

***

### Lab 5 — [Lab 05/](Lab%2005/)

> Exercises: [Lab 5 - Exercises.md](Exercises/Lab%205%20-%20Exercises.md)

- More difficult exercises covering **Loop**,  arrays, and conditional jump control instructions for unsigned and signed.
- **PRINT** and **PRINTN**
- More instrustions:
  - **ADC**: Add with Carry
  - **JC**: if CF = 1 then jump
  - **JNC**: if CF = 0 then jump
- FYI:
  - Printing using **Video Mode**.
  - **PUTC**

| File | Description |
| --- | --- |
| [Ex_34.asm](Lab%2005/Ex_34.asm) | Loop + conditional jumps |
| [Ex_35.asm](Lab%2005/Ex_35.asm) | Signed/unsigned comparison |
| [Ex_36.asm](Lab%2005/Ex_36.asm) | ADC, JC, JNC |
| [Ex_37.asm](Lab%2005/Ex_37.asm) | PRINT / PRINTN |
| [Ex_38.asm](Lab%2005/Ex_38.asm) | Video Mode / PUTC |
| [Ex_39.asm](Lab%2005/Ex_39.asm) | Mixed exercises |
| [Ex_40.asm](Lab%2005/Ex_40.asm) | Mixed exercises |
| [Lab5 Test.asm](Lab%2005/Lab5%20Test.asm) | Lab 5 test program |

***
***

## Threads using C

### Lab 6 — [Lab 06/](Lab%2006/)

- Processes and Threads: Definitions and Differences
- Threads vs Processes
- Need for Multithreading
- Features of Using Threads
- Types of Threads
- Thread Libraries
- Creating and Assigning Work to Threads
- [Compile and Run C Files with Threads](Lab%2006/Compile%20and%20Run%20C%20Files%20with%20Threads.md)
- Pointers & References.

| File | Description |
| --- | --- |
| [Ex_00.c](Lab%2006/Ex_00.c) | Basic thread creation |
| [Ex_01.c](Lab%2006/Ex_01.c) | Thread with argument |
| [Ex_02.c](Lab%2006/Ex_02.c) | Multiple threads |
| [Ex_03.c](Lab%2006/Ex_03.c) | Thread joining |
| [Ex_04.c](Lab%2006/Ex_04.c) | Thread with return value |
| [Ex_05.c](Lab%2006/Ex_05.c) | Pointers & references |
| [Ex_06.c](Lab%2006/Ex_06.c) | Mixed thread concepts |

### Lab 7 — [Lab 07/](Lab%2007/)

- [Struct Usage in C](Lab%2007/struct%20in%20C.md)
- How to use struct to pass multiple values to the thread function
- [Retrieve value from Thread function](Lab%2007/pthread_join.md)
- Passing & Retrieving Multiple Values via Struct
- Synchronization between Threads
- Race condition
- Deadlocks and Livelocks.
- Common Synchronization Tools
  - **mutex (Mutual Exclusion)**
  - **semaphore**

| File | Description |
| --- | --- |
| [struct.c](Lab%2007/struct.c) | Struct basics in C |
| [Ex_07.c](Lab%2007/Ex_07.c) | Struct with threads |
| [Ex_08.c](Lab%2007/Ex_08.c) | Pass multiple values via struct |
| [Ex_09.c](Lab%2007/Ex_09.c) | Retrieve value from thread |
| [Ex_10.c](Lab%2007/Ex_10.c) | Race condition demo |
| [Ex_11.c](Lab%2007/Ex_11.c) | Mutex usage |
| [Ex_12.c](Lab%2007/Ex_12.c) | Mutex usage |
| [Ex_13.c](Lab%2007/Ex_13.c) | Semaphore usage |
| [Ex_14.c](Lab%2007/Ex_14.c) | Deadlock scenario |
| [Ex_15.c](Lab%2007/Ex_15.c) | Synchronization |
| [Ex_16.c](Lab%2007/Ex_16.c) | Synchronization |

### Lab 8 — [Lab 08/](Lab%2008/)

- Case Studies
  - **Producer-Consumer** Problem with Mutex and Condition Variables
  - **Producer-Consumer** Problem with Semaphore
  - **Readers-Writers** Problem
  - **Dining-Philosophers** Problem

| File | Description |
| --- | --- |
| [Producer-Consumer1.c](Lab%2008/Producer-Consumer1.c) | Producer-Consumer with Mutex & Condition Variables |
| [Producer-Consumer2.c](Lab%2008/Producer-Consumer2.c) | Producer-Consumer with Semaphore |
| [ReadersWriters.c](Lab%2008/ReadersWriters.c) | Readers-Writers Problem |
| [dining-philosopher.c](Lab%2008/dining-philosopher.c) | Dining-Philosophers Problem |

### Lab 9 (Practical Exam)

***
***

## Threads using JAVA

### Lab 10 — [Lab 10/](Lab%2010/)

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
- [Lambda Expression](Lab%2010/Lambda%20Expersion.md)
- Using **Future** to wait for the returned value from a thread

| File | Description |
| --- | --- |
| [Ex01_ThreadExample.java](Lab%2010/Ex01_ThreadExample.java) | Thread class basics |
| [Ex02_RunnableExample.java](Lab%2010/Ex02_RunnableExample.java) | Runnable interface |
| [Ex03_VolatileFixExample.java](Lab%2010/Ex03_VolatileFixExample.java) | volatile keyword |
| [Ex04_SynchronizedExample.java](Lab%2010/Ex04_SynchronizedExample.java) | synchronized method/block |
| [Ex05_SimpleLockExample.java](Lab%2010/Ex05_SimpleLockExample.java) | Lock usage |
| [Ex06_SemaphoreExample.java](Lab%2010/Ex06_SemaphoreExample.java) | Semaphore |
| [Ex07_LockConditionExample.java](Lab%2010/Ex07_LockConditionExample.java) | Condition variables |
| [Ex08_ExecutorServiceExample.java](Lab%2010/Ex08_ExecutorServiceExample.java) | ExecutorService |
| [Ex09_ExecutorDemo.java](Lab%2010/Ex09_ExecutorDemo.java) | Executor demo |
| [Ex10_FutureExample.java](Lab%2010/Ex10_FutureExample.java) | Future |
| [Ex11_CallableFutureExample.java](Lab%2010/Ex11_CallableFutureExample.java) | Callable + Future |
| [AccountWithoutSync.java](Lab%2010/AccountWithoutSync.java) | Race condition demo |
| [ArraySum.java](Lab%2010/ArraySum.java) | Parallel array sum |
| [TaskThreadDemo.java](Lab%2010/TaskThreadDemo.java) | Task thread demo |


### Lab 11 (Self-Study) — [Lab 11/](Lab%2011/)

1. **Thread Priorities ([Ex12_MultiThreadPriorityDemo.java](Lab%2011/Ex12_MultiThreadPriorityDemo.java))**
   - Setting thread priorities (`MIN_PRIORITY`, `NORM_PRIORITY`, `MAX_PRIORITY`).
   - OS-dependent scheduling behavior (no strict guarantees).

2. **Wait-Notify Mechanism ([Ex13_WaitNotifyExample.java](Lab%2011/Ex13_WaitNotifyExample.java))**
   - Basic thread coordination using `wait()` and `notify()`.
   - Guarded blocks with `synchronized` and loop checks for spurious wakeups.

3. **Producer-Consumer Pattern ([Ex14_ProducerConsumer.java](Lab%2011/Ex14_ProducerConsumer.java))**
   - Synchronized buffer with `wait()`/`notifyAll()`.
   - Handles empty/full states to prevent race conditions.

4. **ReadWriteLock ([Ex15_ReadWriteExample.java](Lab%2011/Ex15_ReadWriteExample.java))**
   - `ReentrantReadWriteLock` for concurrent reads and exclusive writes.
   - Improves performance in read-heavy scenarios.

5. **CountDownLatch ([Ex16_CountdownLatchExample.java](Lab%2011/Ex16_CountdownLatchExample.java))**
   - One-time synchronization: main thread waits for worker threads.
   - `countDown()` decrements; `await()` blocks until zero.

6. **CyclicBarrier ([Ex17_CyclicBarrierExample.java](Lab%2011/Ex17_CyclicBarrierExample.java))**
   - Reusable barrier for thread synchronization at fixed points.
   - Optional barrier action triggers when all threads arrive.

7. **ThreadLocal ([Ex18_ThreadLocalExample.java](Lab%2011/Ex18_ThreadLocalExample.java) | [Ex19_ThreadLocalExample2.java](Lab%2011/Ex19_ThreadLocalExample2.java))**
   - Thread-local variables for isolated per-thread storage.
   - Two approaches: shared `Map` (Ex18) vs. `Future`/`ExecutorService` (Ex19).

8. **Atomic Operations ([Ex20_AtomicExample.java](Lab%2011/Ex20_AtomicExample.java))**
   - `AtomicInteger` for lock-free, thread-safe counters.
   - Methods like `incrementAndGet()` avoid race conditions.

### Lab 12 (Practical Exam)
  - Tuesday: May 13, 2025

***
***

## Course Info

| | |
| --- | --- |
| **Course Code** | CS306 |
| **Course Instructor** | Dr. Hatem Moharrem |
| **Lab Instructors** | Mahmoud Esmat, Omar Mourad, Ranya Ayman |

---

### Cairo University, Faculty of Science

Department of Mathematics — Computer Science Division
