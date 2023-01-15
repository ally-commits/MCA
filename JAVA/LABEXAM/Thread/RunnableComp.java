class MyThread implements Runnable {
    Thread t;
    MyThread(){
        t = new Thread(this);
        t.start();
    }
    public void run() {
        System.out.print("THREAD CREATING>>...");
    }
}

class RunnableComp {
    public static void main(String args[]) {
        MyThread t = new MyThread();
    }
}