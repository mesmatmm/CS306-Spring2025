
import java.util.concurrent.*;

public class Ex10_FutureExample {
    public static void main(String[] args) {
        // Create a thread pool with a single thread
        ExecutorService executor = Executors.newSingleThreadExecutor();

        // Submit a task to the executor that will return a result in the future
        Future<Integer> future = executor.submit(() -> {
            Thread.sleep(1000); // Simulate long computation
            return 42; // Return the result
        });

        System.out.println("Doing other work while waiting for result...");

        try {
            // Retrieve the result (blocks if not ready)
            Integer result = future.get();
            System.out.println("Got result: " + result);
        } catch (InterruptedException | ExecutionException e) {
            e.printStackTrace(); // Handle exceptions during computation
        } finally {
            executor.shutdown(); // Properly shut down the executor
        }
    }
}
/*

Main points:
    ExecutorService runs tasks asynchronously (in the background).

    submit() starts a task and returns a Future, representing the pending result.

    future.get() waits (blocks) until the result is ready.

    Allows the program to do other work while waiting for the task to finish.

    Always shutdown the executor to free resources.

 */