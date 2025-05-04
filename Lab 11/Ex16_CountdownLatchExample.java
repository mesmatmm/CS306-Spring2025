import java.util.concurrent.CountDownLatch;

/**
 * Demonstrates CountDownLatch usage to make main thread wait for worker threads.
 */
public class Ex16_CountdownLatchExample {
    public static void main(String[] args) throws InterruptedException {
        // Initialize latch with count=3 (must count down 3 times before releasing)
        CountDownLatch latch = new CountDownLatch(3);

        // Worker task that counts down when done
        Runnable worker = () -> {
            System.out.println(Thread.currentThread().getName() + " is working...");
            try {
                Thread.sleep(500); // Simulate work
            } catch (Exception ignored) {}
            System.out.println(Thread.currentThread().getName() + " finished.");
            latch.countDown(); // Decrement latch count
        };

        // Start 3 worker threads
        for (int i = 0; i < 3; i++) new Thread(worker).start();

        latch.await();  // Main thread blocks until latch reaches 0
        System.out.println("All workers are done. Main continues.");
    }
}
/*
Key Points:
    Synchronization Tool: CountDownLatch makes threads wait until a count reaches zero
    Worker Pattern: Main thread waits for N workers to finish
    One-Time Use: Latch cannot be reset after count reaches zero
    Non-Blocking Workers: Workers proceed immediately after countDown()
    Common Use Cases: Server startup, parallel task coordination
 */