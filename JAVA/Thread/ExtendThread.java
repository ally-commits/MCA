class NewThread extends Thread {
    NewThread(String name) {
        super(name);
        start();
    }

    public void run() {
        System.out.println(getName() + " Starting....");

        try {
            for(int count=0;count<10;count++) {
                Thread.sleep(1000);
                System.out.println("IN " + getName() + " count is " + count);
            }
        } catch(InterruptedException exc) {
            System.out.println(getName() + " intrrupted...");
        }
        System.out.println(getName() + " terminating.....");
    }
}

class ExtendThread {
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