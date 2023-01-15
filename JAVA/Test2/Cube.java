import java.util.*;
import java.lang.*;

//Program Name: Input an integer n. Calculate and display the squares and cubes of all integers from 1 to n using two different threads.

class CubeComp extends Thread {
	int n;

	CubeComp(String thrdName,int n){
		super(thrdName);
		this.n = n;
		start();
	}

	public void run() {
		try {
			for(int i=1;i<n;i++) {
				System.out.print("\n" + getName()  +" - Cube of " + i + ":" + (i * i * i) + " Square of " + i + ":" + (i * i));
				Thread.sleep(500);
			}
			System.out.println("\n" + getName() + " Exiting....");
		} catch(InterruptedException exc) {
			System.out.println("Thread Interrupted" + exc);
		}
	}
}

class Cube {
	public static void main(String args[]) {
		CubeComp c1 = new CubeComp("Thread 1", 2);
		CubeComp c2 = new CubeComp("Thread 2", 4);

		try {
			System.out.println("Main thread waiting others threads to finish.");
			c1.join();
			c2.join();
			System.out.println("Main thread exiting.");
		} catch(InterruptedException exc) {
			System.out.println("Thread Interrupted" + exc);
		}
	}
}