public class Ex01_ThreadExample extends Thread {
    @Override
    public void run() {
        System.out.println("Thread is running: " + Thread.currentThread().getName());
    }

    public static void main(String[] args) {
        Ex01_ThreadExample thread = new Ex01_ThreadExample();
        thread.start(); // Starts the new thread
    }
}