package samplePrograms;

class NewThread2 extends Thread {
    NewThread2(String name) {
        super(name);
        start();
    }
    // This is the entry point for the thread.
    public void run() {
       display();
    }
    
    public void display() {
    	 System.out.println("Starting child thread.");
    	 System.out.println("Child Thread:" + Thread.currentThread().toString());
         try {
             for(int i = 5; i > 0; i--) {
            	 
            	 if (Thread.currentThread().getName() == "odd")
            	 {
            		 if (i%2 != 0)
            			 System.out.println("Child Thread - - ODD: " + i); 
            	 }
            	 
            	 if (Thread.currentThread().getName() == "even")
            	 {
            		 if (i%2 == 0)
            			 System.out.println("Child Thread - - Even: " + i); 
            	 }
            	
                 //System.out.println("Child Thread: " + i);
                 Thread.sleep(1000);
             }
         } catch (InterruptedException e) {
             System.out.println("Child interrupted.");
         }
         System.out.println("Exiting child thread.");
    }
}

public class ThreadClassExample {

	public static void main(String[] args) throws InterruptedException{
		// TODO Auto-generated method stub
		new NewThread2("odd");
		new NewThread2("even");
        for(int i = 10; i > 0; i--) {
            System.out.println("Main Thread: " + i);
            Thread.sleep(1000);
        }
	}

}
