class OddThread extends Thread {
    OddThread(String name) {
        super(name);
        start();
    }
    public void run() {
        for(int i=1;i<10;i=i+2) {
            try {
                sleep(1000);
                System.out.println(getName() + "=>" + i + "--" + getPriority());
            } catch(InterruptedException e) {
                System.out.println(e);
            }
        }
    }
}
class EvenThread extends Thread {
    EvenThread(String name) {
        super(name);
        start();
    }
    public void run() {
        for(int i=0;i<10;i=i+2) {
            try {
                sleep(1000);
                System.out.println(getName() + "=>" + i  + "--" + getPriority());
            } catch(InterruptedException e) {
                System.out.println(e);
            }
        }
    }
}

class OddEven {
    public static void main(String args[]) {
        EvenThread t1 = new EvenThread("Even");
        OddThread t2 = new OddThread("Odd");

        Thread tMain = Thread.currentThread();

        System.out.println(t1.isAlive());
        System.out.println(t2.isAlive());
        System.out.println(tMain.isAlive());
    }
}