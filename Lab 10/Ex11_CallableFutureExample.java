
import java.util.concurrent.*;

public class Ex11_CallableFutureExample {
    public static void main(String[] args) {
        // Create a thread pool with 3 threads
        ExecutorService executor = Executors.newFixedThreadPool(3);

        // Create three tasks that return a result
        Callable<String> task1 = () -> {
            Thread.sleep(1000); // Simulate 1 second work
            return "Result from Task 1";
        };

        Callable<String> task2 = () -> {
            Thread.sleep(1500); // Simulate 1.5 seconds work
            return "Result from Task 2";
        };

        Callable<String> task3 = () -> {
            Thread.sleep(500); // Simulate 0.5 second work
            return "Result from Task 3";
        };

        // Submit all tasks to executor and get Future objects
        Future<String> future1 = executor.submit(task1);
        Future<String> future2 = executor.submit(task2);
        Future<String> future3 = executor.submit(task3);

        // Retrieve and print results in order
        try {
            System.out.println(future3.get()); // Should complete first (shortest sleep)
            System.out.println(future1.get());
            System.out.println(future2.get());
        } catch (InterruptedException | ExecutionException e) {
            e.printStackTrace(); // Handle interruptions or task failures
        } finally {
            executor.shutdown(); // Always shutdown the executor service
        }
    }
}

/*

Main Points:
    ExecutorService with a fixed thread pool (3 threads) is used to run tasks concurrently.

    Callable tasks are created, each returning a String result.

    submit() submits tasks and returns a Future for each, representing their pending results.

    future.get() waits (blocks) until the task finishes and gives the actual result.

    Tasks are retrieved in a specific order, but depending on their work time, some results are available earlier (like future3).

    Always shutdown the executor after tasks finish to release resources.

 */

