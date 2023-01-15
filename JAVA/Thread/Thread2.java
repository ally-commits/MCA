class NewThread implements Runnable {
    Thread thrd;
    NewThread(String name) {
        thrd = new Thread(this,name);
        thrd.start();
    }

    public void run() {
        System.out.println(thrd.getName() + " Starting....");

        try {
            for(int count=0;count<10;count++) {
                Thread.sleep(1000);
                System.out.println("IN " + thrd.getName() + " count is " + count);
            }
        } catch(InterruptedException exc) {
            System.out.println(thrd.getName() + " intrrupted...");
        }
        System.out.println(thrd.getName() + " terminating.....");
    }
}

class Thread2 {
    public static void main(String args[]) {
        System.out.println("Main thread starting...");
        NewThread mt = new NewThread("Child #1");
  
        for(int i=0;i<5;i++) {
            System.out.print("Main Thread");
            try {
                Thread.sleep(1000);
            } catch(InterruptedException exc) {
                System.out.println("Main thread intrerupted");
            }
        }
        System.out.println("Main thread ending...");

    }
}