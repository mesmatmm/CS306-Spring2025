
/**
 * SharedData class demonstrates basic wait-notify mechanism for thread coordination.
 * One thread produces data while another consumes it, with proper synchronization.
 */
class SharedData {
    private boolean ready = false;  // Shared flag to indicate data readiness

    // Producer method - marks data as ready and notifies waiting thread
    synchronized void produce() {
        ready = true;
        System.out.println("Produced.");
        notify();  // Wake up any thread waiting on this object's monitor
    }

    // Consumer method - waits until data is ready before consuming
    synchronized void consume() {
        while (!ready) {  // Always use wait() in a loop to guard against spurious wakeups
            try {
                wait();  // Releases lock and waits for notification
            } catch (InterruptedException e) {
                // Handle interruption if needed
            }
        }
        System.out.println("Consumed.");
    }
}

/**
 * Demonstration of producer-consumer pattern using wait() and notify().
 */
public class Ex13_WaitNotifyExample {
    public static void main(String[] args) {
        SharedData data = new SharedData();

        // Start consumer thread first (it will wait)
        new Thread(() -> data.consume()).start();

        // Start producer thread (it will notify)
        new Thread(() -> data.produce()).start();
    }
}
/*
Main Points:
    Synchronized Methods: Both produce() and consume() are synchronized to ensure thread-safe access to the shared ready flag

    Wait-Notify Mechanism:

    wait() releases the lock and puts the thread in waiting state

    notify() wakes up one waiting thread

    Spurious Wakeups Protection: The while (!ready) loop guards against accidental wakeups

    Thread Coordination: Demonstrates basic producer-consumer pattern where:

    Consumer waits for data to be ready

    Producer marks data ready and notifies the consumer

    Order Independence: Works correctly regardless of which thread starts first

    Object Monitor: Uses the intrinsic lock of the SharedData object for synchronization

 */