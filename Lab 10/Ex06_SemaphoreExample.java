
import java.util.concurrent.Semaphore;

public class Ex06_SemaphoreExample {
    private final Semaphore semaphore = new Semaphore(3); // Allow 3 threads to access the resource simultaneously
    private int activeThreads = 0; // Counter for currently active threads inside the critical section

    public void accessResource() {
        try {
            semaphore.acquire(); // Try to acquire a permit (wait if none available)

            // Start of critical section
            synchronized (this) { // Synchronize to safely update activeThreads
                activeThreads++;
                System.out.println(Thread.currentThread().getName() +
                        " acquired permit. Active threads: " + activeThreads);
            }

            Thread.sleep(2000); // Simulate time taken to use the resource

        } catch (InterruptedException e) {
            e.printStackTrace();
        } finally {
            synchronized (this) { // Synchronize to safely update activeThreads before leaving
                activeThreads--;
                System.out.println(Thread.currentThread().getName() +
                        " releasing permit. Active threads: " + activeThreads);
            }
            semaphore.release(); // Release the permit for other threads
        }
    }

    public static void main(String[] args) {
        Ex06_SemaphoreExample example = new Ex06_SemaphoreExample();

        // Create and start 10 threads trying to access the resource
        for (int i = 0; i < 10; i++) {
            new Thread(() -> example.accessResource()).start();
        }
    }
}

