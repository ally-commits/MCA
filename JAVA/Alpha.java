class Alpha implements Runnable{
    int x,y;
    public void run() {
        for(int i=0;i<1000;i++) {
            synchronized(this) {
                x=12;
                y=12;
            }
            System.out.print(x + " "+ y + " ");
        }
    }
    public static void main(String args[]) {
        Alpha a = new Alpha();
        Thread t1 = new Thread(a);
        Thread t2 = new Thread(a);
        t1.start();
        t2.start();
    }
}