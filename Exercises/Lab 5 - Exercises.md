## Lab 5 - Exercises - Assembly - Emu8086

### Table of Contents

1. [Ex_34](#ex_34)
2. [Ex_35](#ex_35)
3. [Ex_36](#ex_36)
4. [Ex_37](#ex_37)
5. [Ex_38](#ex_38)
6. [Ex_39](#ex_39)
7. [Ex_40](#ex_40)

***

### **Ex_34**

Write a program in Assembly language that **saves** the characters of the string ‘**HELLO**’ in array named **MESSAGE** and print them using PUTC. Print the string ‘**DISPLAYING IS DONE**’ at the screen center (row = 12, column = 40).

***

### **Ex_35**

Write a program in Assembly language that **displays** the characters of the string ‘**HELLO**’ that starts after 40 characters from the beginning of DS segment using video mode.  
(Note: the beginning of video mode is B800h i.e. DS = B800h)

***

### **Ex_36**

Write a program in Assembly language that **displays** the characters of the string ‘**HELLO**’ at row = 0 and column = 40 using display mode and ES segment.  
(Note: **ES = B800h**)

***

### **Ex_37**

Using emu8086 program, write a program in Assembly language that **add** two signed byte elements of byte-array **VAR = 80h, 0FFh** and **save** the result in variable named **SUM** then **display** the string '**All done**'.

***

### **Ex_38**

Using emu8086 program, write a program in Assembly language that **adds** the all elements of the unsigned byte array named DATA, which has eight elements: **7Fh, 0B2h, 35h, 0FEh, 0C9h, 80h, 9Eh** and **11h**. **Save** the result in variable **SUM**. Also, **calculate** the average and **save** it in variables **AVGQ** and **AVGR**. **Display** '**summation is done**' after **80** characters from the beginning of **ES segment**, using video mode.  
(Note: **DS = 0B800H in video mode**).

***

### **Ex_39**

Using emu8086 program, write a program in Assembly language that **detects** the maximum student grade of the unsigned byte array **GRADES** which has ten student grades: **69, 87, 96, 45, 13, 55, 100, 73, 37** and **66**. **Save** the maximum grade in a variable **MAX_GRADE** then '**Maximum is detected**'.

***

### **Ex_40**

Using emu8086 program, write a program in Assembly language that **detects** the lowest temperature degree of the signed byte array **DEGREES**, which has eight temperature degrees: **+25, -20, -10, -30, -13, -25, +22** and **+30**. **Save** the minimum degree in a variable **MIN_DEGREE**. Finally, display '**Minimum is detected**' after **160** characters from the beginning of **ES segmen**t using video mode.  
(Note: **ES = 0B800h in video mode**)

***
