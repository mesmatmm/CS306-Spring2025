import java.util.concurrent.locks.*;

/**
 * Demonstration of ReadWriteLock usage to allow concurrent reads
 * while maintaining exclusive access for writes.
 */
public class Ex15_ReadWriteExample {
    // Create a ReadWriteLock (Reentrant implementation)
    private final ReadWriteLock rwLock = new ReentrantReadWriteLock();
    // Shared data that needs protection
    private int sharedData = 0;

    /**
     * Reads the shared data safely using a read lock.
     * Multiple threads can read simultaneously when no writer is active.
     */
    public void readData() {
        // Acquire the read lock (allows multiple concurrent readers)
        rwLock.readLock().lock();
        try {
            // Read operation (thread-safe while read lock is held)
            System.out.println(Thread.currentThread().getName() + " read: " + sharedData);
        } finally {
            // Always release the lock in finally block
            rwLock.readLock().unlock();
        }
    }

    /**
     * Writes to the shared data using a write lock.
     * Provides exclusive access - blocks all readers and other writers.
     * @param value The value to write to shared data
     */
    public void writeData(int value) {
        // Acquire the write lock (exclusive access)
        rwLock.writeLock().lock();
        try {
            // Write operation (exclusive while write lock is held)
            System.out.println(Thread.currentThread().getName() + " wrote: " + value);
            sharedData = value;
        } finally {
            // Always release the lock in finally block
            rwLock.writeLock().unlock();
        }
    }

    public static void main(String[] args) {
        Ex15_ReadWriteExample obj = new Ex15_ReadWriteExample();

        // Create and start a writer thread
        new Thread(() -> obj.writeData(100), "Writer").start();

        // Create and start 3 reader threads
        for (int i = 0; i < 3; i++) {
            // Each reader thread will call readData()
            new Thread(obj::readData, "Reader-" + i).start();
        }
    }
}
/*
Key Features Explained:
    ReadWriteLock Interface:
    ReentrantReadWriteLock implementation allows:
        Multiple concurrent readers when no writer is active
        Exclusive access for a single writer

    Locking Mechanism:
        readLock() for shared read access
        writeLock() for exclusive write access

    Thread Safety:
        All access to sharedData is protected by appropriate locks
        finally blocks ensure locks are always released
    Concurrency Benefits:
        Readers don't block other readers
        Writer blocks all readers and other writers
        Better performance than full synchronization when reads outnumber writes
    Main Method:
        Starts 1 writer thread (sets value to 100)
        Starts 3 reader threads (read the shared value)
        Thread naming helps track execution order in output

    Expected Behavior:
        Writer thread gets exclusive access to update the value
        Reader threads can read concurrently when no writer is active

    Output will show either:
        Writer completes first, then readers see new value
        Some readers may see old value if they execute before writer

    Best Practices Illustrated:
        Always release locks in finally blocks
        Use thread naming for debugging
        Separate read and write operations appropriately
        Document thread safety guarantees
 */