import java.util.*;

class CalculateSum {
	int arr[][] = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};

	 int calculateData(String Name,int index) {
		System.out.println(Name + " is Executing....");

		int rowSum = 0;
		try {
			for(int j=0;j<arr[index].length;j++){
				rowSum += arr[index][j];
				Thread.sleep(400);
			}

		} catch(InterruptedException e) {
			System.out.println(e);
		}
		System.out.println(Name + " Sum of row " + (index + 1) + ":" + rowSum);
		System.out.println(Name + " Exited..\n");
		return rowSum;
	}
}

class MultiArrThread implements Runnable{
	Thread t;
	CalculateSum c;
	int index;
	private int rowSum;

	MultiArrThread(CalculateSum c,int index)  {
		t = new Thread(this,"Thread " + index);
		this.c = c;
		this.index = index;
		t.start();
	}
	public void run() {
		rowSum = c.calculateData(t.getName(),index - 1);
	}
	int getRowSum() {
		return rowSum;
	}
}

class MultiArr {
	public static void main(String args[]) {
		CalculateSum c = new CalculateSum();

		MultiArrThread t1 = new MultiArrThread(c,1);
		MultiArrThread t2 = new MultiArrThread(c,2);
		MultiArrThread t3 = new MultiArrThread(c,3);

		try {
			t1.t.join();
			t2.t.join();
			t3.t.join();

			System.out.println("Main Thread : Sum of Array:" + (t1.getRowSum() + t2.getRowSum()+ t3.getRowSum()));
		} catch(InterruptedException e) {
			System.out.println(e);
		}
	}
}
