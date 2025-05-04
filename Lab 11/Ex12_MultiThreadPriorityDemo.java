
/**
 * This class demonstrates thread priorities in Java with 5 threads.
 * Each thread has a different priority level, showing how the JVM
 * may (but doesn't always) prioritize higher-priority threads.
 */
public class Ex12_MultiThreadPriorityDemo {
    public static void main(String[] args) {
        // Create 5 threads with different priorities
        Thread t1 = new Thread(() -> {
            for (int i = 0; i < 5; i++) {
                System.out.println("Thread 1 - MIN_PRIORITY (1)");
            }
        });

        Thread t2 = new Thread(() -> {
            for (int i = 0; i < 5; i++) {
                System.out.println("Thread 2 - Priority 3");
            }
        });

        Thread t3 = new Thread(() -> {
            for (int i = 0; i < 5; i++) {
                System.out.println("Thread 3 - NORM_PRIORITY (5)");
            }
        });

        Thread t4 = new Thread(() -> {
            for (int i = 0; i < 5; i++) {
                System.out.println("Thread 4 - Priority 7");
            }
        });

        Thread t5 = new Thread(() -> {
            for (int i = 0; i < 5; i++) {
                System.out.println("Thread 5 - MAX_PRIORITY (10)");
            }
        });

        // Set different priorities (1 to 10)
        t1.setPriority(Thread.MIN_PRIORITY);      // Priority 1 (lowest)
        t2.setPriority(3);                         // Custom priority 3
        t3.setPriority(Thread.NORM_PRIORITY);      // Priority 5 (default)
        t4.setPriority(7);                         // Custom priority 7
        t5.setPriority(Thread.MAX_PRIORITY);       // Priority 10 (highest)

        // Start all threads
        t1.start();
        t2.start();
        t3.start();
        t4.start();
        t5.start();
    }
}
/*
Expected Behavior:
    - Higher-priority threads (e.g., t5) are more likely to execute first, but not guaranteed.
    - The JVM and OS scheduler ultimately decide the execution order.
Note: While higher priority threads are more likely to be scheduled first, this behavior
 isn't guaranteed as it depends on the JVM implementation and OS scheduling.
 */