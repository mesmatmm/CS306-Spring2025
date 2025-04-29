
import java.util.concurrent.locks.*;

public class Ex07_LockConditionExample {
    private final Lock lock = new ReentrantLock(); // Lock to control access
    private final Condition condition = lock.newCondition(); // Condition for signaling between threads
    private boolean ready = false; // Shared flag indicating if the producer has produced

    public void producer() {
        lock.lock(); // Acquire the lock before accessing shared data
        try {
            System.out.println("Producer is producing...");
            Thread.sleep(2000); // Simulate some work being done
            ready = true; // Mark that production is done
            condition.signal(); // Signal the waiting consumer
            System.out.println("Producer signaled.");
        } catch (InterruptedException e) {
            e.printStackTrace();
        } finally {
            lock.unlock(); // Always release the lock
        }
    }

    public void consumer() {
        lock.lock(); // Acquire the lock before accessing shared data
        try {
            while (!ready) { // Wait until the producer signals
                System.out.println("Consumer waiting...");
                condition.await(); // Wait (release lock temporarily)
            }
            System.out.println("Consumer consumed."); // Proceed after being signaled
        } catch (InterruptedException e) {
            e.printStackTrace();
        } finally {
            lock.unlock(); // Always release the lock
        }
    }

    public static void main(String[] args) {
        Ex07_LockConditionExample example = new Ex07_LockConditionExample();

        // Start the consumer and producer in separate threads
        new Thread(() -> example.consumer()).start();
        new Thread(() -> example.producer()).start();
    }
}

