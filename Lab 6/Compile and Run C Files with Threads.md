To compile and run C files (including those using threads) via the Command Prompt (cmd) in Windows, you'll need a C compiler like **GCC** (from **MinGW** or **MSYS2**) or **Microsoft's MSVC** (via **Visual Studio**).  

Here are the commands for **GCC (MinGW)** since it's commonly used for multi-threaded C programs:

### **1. Install GCC (MinGW)**
If you don't have GCC installed:
- Download **MinGW** from [https://sourceforge.net/projects/mingw/](https://sourceforge.net/projects/mingw/)  
- Install it and add `gcc` to your **PATH** (e.g., `C:\MinGW\bin`).

Alternatively, use **MSYS2** (recommended for better package management):
- Download from [https://www.msys2.org/](https://www.msys2.org/)
- Run in MSYS2 terminal:  
  ```sh
  pacman -S mingw-w64-x86_64-gcc
  ```
- Add `C:\msys64\mingw64\bin` to **PATH**.

---

### **2. Compile a C File (Without Threads)**
```sh
gcc myfile.c -o myprogram
```
- `myfile.c` → Your C source file.
- `-o myprogram` → Output executable name.

---

### **3. Compile a C File With Threads (POSIX Threads - `pthread`)**
If your program uses `pthread.h` (common for threading in C), link the `pthread` library:
```sh
gcc myfile.c -o myprogram -pthread
```
- `-pthread` ensures proper thread linking.

---

### **4. Run the Compiled Program**
```sh
myprogram
```
or
```sh
.\myprogram.exe
```

---

### **Example: Full Process for a Threaded Program**
Suppose you have `thread_example.c`:
```c
#include <stdio.h>
#include <pthread.h>

void* thread_func(void* arg) {
    printf("Thread running!\n");
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, thread_func, NULL);
    pthread_join(thread, NULL);
    printf("Main thread done.\n");
    return 0;
}
```

#### **Compile & Run:**
```sh
gcc thread_example.c -o thread_example -pthread
.\thread_example.exe
```

---

### **Alternative: Using Microsoft's MSVC (Visual Studio)**
If you have **Visual Studio** installed, you can use **MSVC**:
1. Open **Developer Command Prompt for VS** (search in Start menu).
2. Compile:
   ```sh
   cl myfile.c
   ```
3. Run:
   ```sh
   myfile.exe
   ```
- For threads, MSVC uses `<windows.h>` and `CreateThread()` instead of `pthread.h`.

---

### **Summary**
| Task | Command |
|------|---------|
| **Compile normally** | `gcc file.c -o output` |
| **Compile with threads** | `gcc file.c -o output -pthread` |
| **Run** | `.\output.exe` |

---
