class Sample {
    public static void main(String args[]) {
        Thread t = Thread.currentThread();

        System.out.println(t);

        t.setName("My Thread");

        System.out.println(t.getName());

        try {
            for(int i=0;i<10;i++) {
                System.out.println(i);
                Thread.sleep(1000);
            }
        } catch(InterruptedException e) {
            System.out.println(e);
        }
    }
}