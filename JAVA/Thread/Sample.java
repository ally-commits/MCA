class MyThread implements Runnable {
    String thrdName;
    
    MyThread(String name) {
        thrdName = name;
    }

    public void run() {
        System.out.println(thrdName + " Starting....");

        try {
            for(int count=0;count<5;count++) {
                Thread.sleep(1000);
                System.out.println("IN " + thrdName + " count is " + count);
            }
        } catch(InterruptedException exc) {
            System.out.println(thrdName + " intrrupted...");
        }
        System.out.println(thrdName + " terminating.....");
    }
}

class Sample {
    public static void main(String args[]) {
        System.out.println("Main thread starting...");
        MyThread mt = new MyThread("Child #1");

        Thread newThrd = new Thread(mt);

        newThrd.start();
        for(int i=0;i<10;i++) {
            System.out.print("Main Thread");
            try {
                Thread.sleep(2000);
            } catch(InterruptedException exc) {
                System.out.println("Main thread intrerupted");
            }
        }
        System.out.println("Main thread ending...");

    }
}