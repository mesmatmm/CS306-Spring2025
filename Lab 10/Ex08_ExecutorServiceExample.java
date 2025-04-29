
import java.util.concurrent.*;

public class Ex08_ExecutorServiceExample {
    public static void main(String[] args) {
        // Create a thread pool with 2 threads
        ExecutorService executor = Executors.newFixedThreadPool(2);
        //ExecutorService executor = Executors.newCachedThreadPool();

        // Submit tasks to the executor
        executor.submit(() -> {
            System.out.println("Task 1 running in " + Thread.currentThread().getName());
        });

        executor.submit(() -> {
            System.out.println("Task 2 running in " + Thread.currentThread().getName());
        });

        executor.submit(() -> {
            System.out.println("Task 3 running in " + Thread.currentThread().getName());
        });
        // Shutdown the executor
        executor.shutdown();
        System.out.println("MAIN ENDED");
    }
}
