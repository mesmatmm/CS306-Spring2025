
public class Ex04_SynchronizedExample {
    private int count = 0;

    public synchronized void increment() {
            count++;
    }

    public void doWork() {
        Thread t1 = new Thread(() -> {
            for (int i = 0; i < 10000; i++) {
                increment();
            }
        });

        Thread t2 = new Thread(() -> {
            for (int i = 0; i < 10000; i++) {
                increment();
            }
        });

        t1.start();
        t2.start();

        try {
            t1.join();
            t2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Count is: " + count);
    }

    public static void main(String[] args) {
        new Ex04_SynchronizedExample().doWork();
    }
}
/*
This Java code demonstrates using `synchronized` to safely update a shared variable (`count`) from multiple threads.

**Summary:**
- `count` starts at 0.
- `increment()` is a synchronized method, meaning **only one thread can execute it at a time**, preventing race conditions.
- `doWork()` creates two threads (`t1` and `t2`), each calling `increment()` **10,000 times**.
- After both threads finish (using `join()`), it prints the final value of `count`, which should correctly be `20000`.

**Main point:**
`synchronized` ensures that updating `count` is thread-safe, avoiding issues like lost updates.


 */