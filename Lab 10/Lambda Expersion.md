### **Lambda Expression in Java - Simple Explanation**

A **lambda expression** is a **shortcut** to write a small piece of code that can be passed around like a variable. It’s mainly used to implement **functional interfaces** (interfaces with a **single abstract method**, like `Runnable`, `Callable`, or `Comparator`).

---

### **🔹 Traditional Way (Without Lambda)**
```java
Runnable r = new Runnable() {
    @Override
    public void run() {
        System.out.println("Hello from Runnable!");
    }
};
new Thread(r).start();
```

### **🔹 With Lambda (Shorter & Cleaner)**
```java
Runnable r = () -> System.out.println("Hello from Lambda!");
new Thread(r).start();
```
**OR even shorter:**
```java
new Thread(() -> System.out.println("Hello from Lambda!")).start();
```

---

### **🔹 Lambda Syntax**
```java
(parameters) -> { body }
```
- If **only one parameter**, parentheses `()` are optional.
- If **only one statement**, braces `{}` and `return` are optional.

| Example | Meaning |
|---------|---------|
| `() -> System.out.println("Hi")` | Takes **no input**, prints "Hi" |
| `(x) -> x * 2` | Takes **x**, returns `x * 2` |
| `(a, b) -> a + b` | Takes **a and b**, returns `a + b` |
| `s -> s.length() > 5` | Takes **s**, checks if length > 5 |

---

### **🔹 Where Are Lambdas Used?**
1. **With `Runnable` (Threads)**
   ```java
   new Thread(() -> System.out.println("Running in a thread!")).start();
   ```

2. **With `Comparator` (Sorting)**
   ```java
   List<String> names = Arrays.asList("Alice", "Bob", "Charlie");
   names.sort((a, b) -> a.length() - b.length());
   ```

3. **With `forEach` (Collections)**
   ```java
   List<Integer> numbers = List.of(1, 2, 3);
   numbers.forEach(num -> System.out.println(num * 2));
   ```

---

### **🔹 Why Use Lambdas?**
✅ **Shorter code** – No need for anonymous classes.  
✅ **Readable** – Focuses on **what** the code does, not boilerplate.  
✅ **Functional programming** – Enables passing behavior as data.

---

### **🔹 Real-World Analogy**
Imagine you want to **order a pizza**:
- **Traditional way** → Write a full letter explaining how to make it.
- **Lambda way** → Just say **"Pepperoni, large"** (short and clear).

---

### **🔹 Summary**
- **Lambda = Shortcut for single-method interfaces**
- **Syntax:** `(params) -> { body }`
- **Used in threads, sorting, streams, etc.**

