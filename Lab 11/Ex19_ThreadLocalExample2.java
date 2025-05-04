import java.util.concurrent.*;
import java.util.*;
/*
Alternative Approach (Using Future/Callable): For Ex17
For more robust result handling, you could also use Callable with ExecutorService and Future:

This second approach is more modern and provides better control over thread execution and result retrieval.
 */
public class Ex19_ThreadLocalExample2 {
    static ThreadLocal<Integer> threadLocal = ThreadLocal.withInitial(() -> 0);

    public static void main(String[] args) throws InterruptedException, ExecutionException {
        ExecutorService executor = Executors.newFixedThreadPool(5);
        List<Future<Integer>> futures = new ArrayList<>();

        for (int i = 0; i < 5; i++) {
            futures.add(executor.submit(new CallableTask()));
        }

        System.out.println("\nThread results after completion:");
        for (int i = 0; i < futures.size(); i++) {
            System.out.println("Thread-" + (i+1) + ": " + futures.get(i).get());
        }

        executor.shutdown();
    }

    static class CallableTask implements Callable<Integer> {
        @Override
        public Integer call() {
            int randomValue = (int)(Math.random() * 100);
            threadLocal.set(randomValue);
            System.out.println(Thread.currentThread().getName() + " running: " + threadLocal.get());
            return threadLocal.get();
        }
    }
}