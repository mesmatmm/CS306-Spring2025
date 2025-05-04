import java.util.concurrent.*;

/**
 * Demonstrates CyclicBarrier usage to synchronize threads at a common point.
 */
public class Ex17_CyclicBarrierExample {
    public static void main(String[] args) {
        // Create a CyclicBarrier for 3 threads with a barrier action
        CyclicBarrier barrier = new CyclicBarrier(3,
                // This runs when all threads reach the barrier
                () -> System.out.println("All threads reached the barrier, continue together.")
        );

        // Task that threads will execute
        Runnable task = () -> {
            System.out.println(Thread.currentThread().getName() + " is waiting.");
            try {
                // Simulate variable work time (0-1000ms)
                Thread.sleep((int)(Math.random() * 1000));

                // Wait here until all 3 threads reach this point
                barrier.await();

                // This executes after all threads pass the barrier
                System.out.println(Thread.currentThread().getName() + " passed the barrier.");
            } catch (Exception ignored) {
                // Handle interruption or barrier broken exceptions
            }
        };

        // Start 3 threads (must match barrier's party count)
        for (int i = 0; i < 3; i++) {
            new Thread(task).start();
        }
    }
}
/*
Key Points:
    Synchronization Tool: Coordinates threads to wait for each other at a barrier point
    Reusable: Unlike CountDownLatch, can be reset after threads are released
    Barrier Action: Optional callback that runs when all threads reach the barrier
    Thread Count: Number of threads must match the barrier's party count (3 in this case)
    Use Cases: Parallel computation phases, multi-threaded testing

Behavior Flow:
    Each thread works independently until calling await()
    Threads block at the barrier until all 3 arrive
    Barrier action executes (if provided)
    All threads are released simultaneously
    Threads continue execution after the barrier

This pattern is useful for synchronizing phases of parallel computation where threads need to wait for peers before proceeding.
 */