// Import the AtomicInteger class from java.util.concurrent.atomic package
// This provides atomic operations on integers for thread-safe programming
import java.util.concurrent.atomic.AtomicInteger;

public class Ex20_AtomicExample {
    // Create an AtomicInteger counter initialized to 0
    // AtomicInteger provides thread-safe operations without explicit synchronization
    static AtomicInteger counter = new AtomicInteger(0);

    public static void main(String[] args) throws InterruptedException {
        // Define a Runnable task that will be executed by multiple threads
        // This task increments the counter 1000 times
        Runnable increment = () -> {
            // Loop 1000 times to increment the counter
            for (int i = 0; i < 1000; i++) {
                // Atomically increment the counter by 1
                // This operation is thread-safe and prevents race conditions
                counter.incrementAndGet();
            }
        };

        // Create two threads that will execute the increment task
        Thread t1 = new Thread(increment);
        Thread t2 = new Thread(increment);

        // Start both threads
        t1.start();
        t2.start();

        // Wait for both threads to complete their execution
        // join() makes the main thread wait until t1 and t2 finish
        t1.join();
        t2.join();

        // Print the final value of the counter
        // Since we used AtomicInteger, the result should be exactly 2000
        // (1000 increments from each thread) with no race conditions
        System.out.println("Counter: " + counter.get());
    }
}
/**
 * Key Points Explained:
 *
 * AtomicInteger:
 * - A thread-safe integer class that provides atomic operations
 * - Ensures that operations like increment are performed atomically without race conditions
 *
 * incrementAndGet():
 * - Atomically increments the current value by 1
 * - Equivalent to ++counter but thread-safe
 *
 * Thread Management:
 * - Two threads are created to execute the same increment task
 * - start() begins thread execution
 * - join() makes the main thread wait for completion
 *
 * Thread Safety:
 * - Without AtomicInteger, this could result in lost updates due to race conditions
 * - With AtomicInteger, the final count will always be 2000 (assuming no exceptions)
 *
 * Expected Output:
 * - The program will consistently print "Counter: 2000" because the atomic operations
 *   prevent race conditions between threads
 */