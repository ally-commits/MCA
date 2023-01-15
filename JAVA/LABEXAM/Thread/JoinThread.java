class NewThread extends Thread{
    NewThread(String name){
        super(name);
        start();
    }

    public void run() {
        for(int i=0;i<10;i++) {
            try {
                sleep(1000);
                System.out.println(getName() + "--" + i);
            } catch(InterruptedException e) {
                System.out.println(e);
            }
        }
    }
}


class JoinThread {
    public static void main(String args[]) {
        NewThread t1 = new NewThread("Thread 1");
        NewThread t2 = new NewThread("Thread 2");
        NewThread t3 = new NewThread("Thread 3");

        try {
            System.out.println("MAIN THREAD EXECUTING");
            t1.join();
            t2.join();
            t3.join();
            System.out.println("MAIN THREAD EXITED");
        } catch(InterruptedException e) {
            System.out.println(e);
        }
         
    }
}