
/**
 * Thread-safe Buffer class that implements producer-consumer pattern
 * using wait-notify mechanism for proper thread synchronization.
 */
class Buffer {
    private int data;          // Shared data between producers and consumers
    private boolean available = false;  // Flag indicating if data is available for consumption

    /**
     * Produces a value and stores it in the buffer.
     * @param value The value to be produced
     * @throws InterruptedException if the thread is interrupted while waiting
     */
    public synchronized void produce(int value) throws InterruptedException {
        // Wait while data is available (buffer is full)
        while (available) {
            wait();  // Releases lock and waits for consumer to consume
        }

        data = value;          // Store the produced value
        available = true;      // Mark buffer as having available data
        System.out.println("Produced: " + value);
        notifyAll();           // Notify all waiting consumers
    }

    /**
     * Consumes the value from the buffer.
     * @return The consumed value
     * @throws InterruptedException if the thread is interrupted while waiting
     */
    public synchronized int consume() throws InterruptedException {
        // Wait while no data is available (buffer is empty)
        while (!available) {
            wait();  // Releases lock and waits for producer to produce
        }

        available = false;     // Mark buffer as empty
        System.out.println("Consumed: " + data);
        notifyAll();           // Notify all waiting producers
        return data;          // Return the consumed value
    }
}

/**
 * Demonstration of producer-consumer pattern with single producer and single consumer.
 */
public class Ex14_ProducerConsumer {
    public static void main(String[] args) {
        Buffer buffer = new Buffer();  // Shared buffer

        // Producer thread produces values 1 through 5
        Thread producer = new Thread(() -> {
            for (int i = 1; i <= 5; i++) {
                try {
                    buffer.produce(i);  // Produce value
                    Thread.sleep(100); // Simulate production time
                } catch (InterruptedException ignored) {
                    // Handle interruption (in this case, just ignore)
                }
            }
        });

        // Consumer thread consumes 5 values
        Thread consumer = new Thread(() -> {
            for (int i = 1; i <= 5; i++) {
                try {
                    buffer.consume();   // Consume value
                    Thread.sleep(150);  // Simulate consumption time
                } catch (InterruptedException ignored) {
                    // Handle interruption (in this case, just ignore)
                }
            }
        });

        producer.start();  // Start producer thread
        consumer.start();   // Start consumer thread
    }
}
/*
Key Points:
        Thread Safety: All buffer operations are synchronized to prevent race conditions
        Wait-Notify Mechanism:
                - Producers wait when buffer is full (while (available))
                - Consumers wait when buffer is empty (while (!available))
                - notifyAll() wakes up all waiting threads

        Buffer State Tracking: available flag indicates whether data can be consumed
        Production/Consumption Rate:
                Producer sleeps 100ms between productions (faster)
                Consumer sleeps 150ms between consumptions (slower)
        Spurious Wakeups Protection: while loops guard against accidental wakeups
        Interruption Handling: Ignores interruptions for simplicity (real code might handle differently)

        This implementation ensures proper synchronization between producer and consumer threads,
        preventing both buffer overflow and underflow conditions.
 */