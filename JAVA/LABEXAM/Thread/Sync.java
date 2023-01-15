class SyncClass {
    void display(String name) {
        System.out.print("\n[");
        try {
            Thread.sleep(1000);
            System.out.print(name);
        } catch(InterruptedException e) {
            System.out.print(e);
        }
        System.out.print("]\n");
    }
}

class MyThread extends Thread {
    SyncClass s;
    String name;
    MyThread(SyncClass s,String name) {
        this.s = s;
        this.name = name;
        start();
    }

    public void run() {
        synchronized(s) {
            s.display(name);
        };
    }
}

class Sync {
    public static void main(String args[]) {
        SyncClass s = new SyncClass();

        MyThread t1 = new MyThread(s, "ONE");
        MyThread t2 = new MyThread(s, "TWO");
        MyThread t3 = new MyThread(s, "THREE");
        MyThread t4 = new MyThread(s, "FOUR");


    }
}
