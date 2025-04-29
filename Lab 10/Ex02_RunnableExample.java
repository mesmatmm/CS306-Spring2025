public class Ex02_RunnableExample implements Runnable {
    @Override
    public void run() {
        System.out.println("Runnable is running: " + Thread.currentThread().getName());
    }

    public static void main(String[] args) {
        Ex02_RunnableExample runnable = new Ex02_RunnableExample();
        Thread thread1 = new Thread(runnable);
        Thread thread2 = new Thread(runnable);
        thread1.start();
        thread2.start();
    }
}