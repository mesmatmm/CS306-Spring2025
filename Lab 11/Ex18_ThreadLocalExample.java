import java.util.HashMap;
import java.util.Map;

public class Ex18_ThreadLocalExample {
    // ThreadLocal variable to store integer values
    static ThreadLocal<Integer> threadLocal = ThreadLocal.withInitial(() -> 0);

    // Map to store thread results after they finish
    static Map<String, Integer> threadResults = new HashMap<>();

    public static void main(String[] args) throws InterruptedException {
        // Create an array to hold the threads
        Thread[] threads = new Thread[5];

        // Create and start 5 threads
        for (int i = 0; i < 5; i++) {
            threads[i] = new Thread(new Task(), "Thread-" + (i + 1));
            threads[i].start();
        }

        // Wait for all threads to complete
        for (Thread thread : threads) {
            thread.join();
        }

        // Print all thread results after they've finished
        System.out.println("\nThread results after completion:");
        threadResults.forEach((name, value) ->
                System.out.println(name + ": " + value));
    }

    static class Task implements Runnable {
        @Override
        public void run() {
            // Generate a random value for this thread
            int randomValue = (int)(Math.random() * 100);

            // Store it in thread-local storage
            threadLocal.set(randomValue);

            // Print the current value
            System.out.println(Thread.currentThread().getName() + " running: " + threadLocal.get());

            // Store the result in the shared map before thread finishes
            synchronized (threadResults) {
                threadResults.put(Thread.currentThread().getName(), threadLocal.get());
            }
        }
    }
}
/*
Key Points:
    Creating 5 Threads: The code now creates and manages an array of 5 threads.
    Thread-Local Data: Each thread still maintains its own thread-local value.
    Storing Results: To access the data after threads finish, we use a synchronized Map to store each thread's result before it terminates.
    Thread Joining: The main thread waits for all worker threads to complete using join().
    Result Access: After all threads finish, the main thread prints the collected results from the shared map.
 */