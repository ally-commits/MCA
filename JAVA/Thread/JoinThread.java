class NewThread extends Thread {
    int n;
    NewThread(String name,int n) {
        super(name);
        start();
        this.n = n;
    }

    public void run() {
        System.out.println(getName() + " Starting....");

        try {
            for(int count=0;count<n;count++) {
                Thread.sleep(1000);
                System.out.println("INSIDE " + getName() + " count is " + count);
            }
        } catch(InterruptedException exc) {
            System.out.println(getName() + " intrrupted...");
        }
        System.out.println(getName() + " terminating.....");
    }
}

class JoinThread {
    public static void main(String args[]) {
        System.out.println("Main thread starting...");
        NewThread mt1 = new NewThread("Child #1",10);
        NewThread mt2 = new NewThread("Child #2",5);
        NewThread mt3 = new NewThread("Child #3",2);
  
  
        try {
            System.out.println("Main Thread Line 1");
            mt1.join();
            System.out.println("Main Thread Line 2");
            mt2.join();
            System.out.println("Main Thread Line 3");
            mt3.join();
            System.out.println("Main Thread Line 4");
        } catch(InterruptedException exc) {
            System.out.println("Main thread intrerupted");
        } 
        System.out.println("Main thread ending...");

    }
}