import java.util.concurrent.*;

public class ArraySum {

  public static void main(String[] args) throws InterruptedException, ExecutionException {
    // Create and initialize an array with 1000 elements
    int[] array = new int[1000];
    // Initialize array with values 1 to 1000
    for (int i = 0; i < array.length; i++) {
      array[i] = i + 1;
    }

    // Set the number of threads to use for parallel processing
    int numThreads = 10;
    // Create a thread pool with fixed number of threads
    ExecutorService executor = Executors.newFixedThreadPool(numThreads);
    // Array to store Future objects that will hold the results from each thread
    Future<Integer>[] results = new Future[numThreads];

    // Calculate the size of each chunk of the array to be processed by each thread
    int chunkSize = array.length / numThreads;

    // Divide the work among threads
    for (int i = 0; i < numThreads; i++) {
      // Calculate the start index for this thread's chunk
      final int start = i * chunkSize;
      // Calculate the end index (for last thread, make sure to include remaining elements)
      final int end = (i == numThreads - 1) ? array.length : start + chunkSize;

      // Submit a task to the executor for each chunk
      results[i] = executor.submit(() -> {
        int sum = 0;
        // Sum the elements in this thread's assigned chunk
        for (int j = start; j < end; j++) {
          sum += array[j];
        }
        return sum;
      });
    }

    // Combine results from all threads
    int totalSum = 0;
    for (Future<Integer> result : results) {
      // Wait for each thread to complete and get its result
      // Note: get() will block until the result is available
      totalSum += result.get();
    }

    // Shutdown the executor service to release resources
    executor.shutdown();
    // Print the final total sum
    System.out.println("Total Sum: " + totalSum);
  }
}
/*
Key points explained in the comments:
    1- Array initialization with values 1 to 1000
    2- Thread pool creation with a fixed number of threads
    3- Division of work into chunks for parallel processing
    4- Handling of the last chunk which might be slightly larger if the array size isn't perfectly divisible
    5- The lambda expression that each thread executes to sum its portion
    6- Collection and combination of results from all threads
    7- Proper shutdown of the executor service
    8- Output of the final result

The code demonstrates a common parallel processing pattern using Java's ExecutorService and
 Future interfaces to efficiently sum a large array by dividing the work among multiple threads.
 */