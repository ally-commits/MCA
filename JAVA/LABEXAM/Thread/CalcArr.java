import java.util.*;

class Arr { 
    int arr[] = {1,2,3,4,5}; 

    Scanner sn = new Scanner(System.in);
     
    void calculate(int val) {
        for(int i=0;i<arr.length;i++) {
            arr[i] = arr[i] / val;
        }
    }
    void display() {
        System.out.print("\n");
        for(int i=0;i<arr.length;i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.print("\n");
    }
}

class MyThread extends Thread {
    Arr a;
    int val;
    MyThread(Arr a,int val) {
        this.a = a;
        this.val = val;
        start();
    }

    public void run() {
        a.calculate(val);
    }
}

class CalcArr {
    public static void main(String args[]) {
        Arr a1 = new Arr();
        Arr a2 = new Arr();

        MyThread t1 = new MyThread(a1,1);
        MyThread t2 = new MyThread(a2,2);

        a1.display();
        a2.display();
    }
}