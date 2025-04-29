public class Ex03_VolatileFixExample {
    private static volatile boolean flag = false; // Now volatile!

    public static void main(String[] args) {
        // Thread 1: Checks the flag
        new Thread(() -> {
            while (!flag) {
                // Waits until flag becomes true
            }
            System.out.println("Thread 1: Flag is now TRUE!");
        }).start();

        // Thread 2: Changes the flag after 1 second
        new Thread(() -> {
            try {
                Thread.sleep(1000);
                flag = true;
                System.out.println("Thread 2: Flag set to TRUE");
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }).start();
    }
}
/*
Problem Without volatile:
- Thread 1 might never see the updated value of flag from Thread 2 due to CPU caching.

Key Points:
✔ volatile ensures Thread 1 immediately sees changes made by Thread 2.
✔ Without volatile, Java might cache the value of flag in Thread 1's CPU cache.
✔ Use volatile when one thread writes, and another thread reads a variable.

When to Use volatile?
- For simple flags (like boolean flag).
- When only one thread updates the variable.
- For lightweight synchronization (but for complex operations, use synchronized or Lock instead).

 */