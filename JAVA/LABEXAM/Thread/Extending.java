class MyThreadA extends Thread{
    MyThreadA(String name) {
        super(name);
        start();
    }

    public void run() {
        for(int i=1;i<5;i++) {
            System.out.println(getName() + "=>" + i);
            try {
                sleep(1000);
            } catch(InterruptedException e) {
                System.out.println(e);
            }
        }
    }
}
class MyThreadB extends Thread{
    MyThreadB(String name) {
        super(name);
        start();
    }

    public void run() {
        for(int i=1;i<5;i++) {
            System.out.println(getName() + "=>" + i);
            try {
                sleep(1000);
            } catch(InterruptedException e) {
                System.out.println(e);
            }
        }
    }
}

class Extending {
    public static void main(String args[]) {
        MyThreadA A = new MyThreadA("MyThread A");
        MyThreadB B = new MyThreadB("MyThread B");
    }
}