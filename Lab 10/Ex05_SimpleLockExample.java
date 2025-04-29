
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Ex05_SimpleLockExample {
    private final Lock lock = new ReentrantLock();
    private int counter = 0;

    public void increment() {
        lock.lock(); // Acquire the lock
        try {
            counter++; // Critical section
            System.out.println(Thread.currentThread().getName() + ": Counter = " + counter);
        } finally {
            lock.unlock(); // Always release the lock in finally block
        }
    }

    public static void main(String[] args) {
        Ex05_SimpleLockExample example = new Ex05_SimpleLockExample();

        // Create 3 threads that increment the counter
        for (int i = 0; i < 3; i++) {
            new Thread(() -> {
                for (int j = 0; j < 5; j++) {
                    example.increment();
                    try {
                        Thread.sleep(100); // Simulate some work
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }).start();
        }
    }
}
/*
Key Points:
- Lock Creation: Lock lock = new ReentrantLock();
- Acquiring Lock: lock.lock(); (blocks until lock is available)
- Releasing Lock: lock.unlock(); (must be in finally block)
- Critical Section: The code between lock() and unlock()

Why Use Lock Instead of synchronized?
    - More flexible (can try to acquire lock with timeout)
    - Can be acquired in one method and released in another
    - Supports multiple Condition objects
    - Better performance in some cases
 */