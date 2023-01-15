class OddThread extends Thread {
    int arr[];

    OddThread(int arr[]) {
        this.arr = arr;
        start();
    }

    public void run() {
        int count = 0;
        for(int i=1;i<100;i=i+2) {
            arr[count++] = i;
        }
    }
}

class Mul5Thread extends Thread {
    int arr[];
    
    Mul5Thread(int arr[]) {
        this.arr = arr;
        start();
    }

    public void run() {
        int count = 0;
        for(int i=1;i<100;i++) {
            if(i % 5 == 0)
                arr[count++] = i;
        }
    }
}
public class ArrManip {
    public static void main(String args[]) {
        int arr1[] = new int[50];
        int arr2[] = new int[20];

        OddThread t1 = new OddThread(arr1);
        Mul5Thread t2 = new Mul5Thread(arr2);

        try {
            t1.join();
            t2.join(); 

            for(int i=0;i<arr1.length;i++) {
                for(int j=0;j<arr2.length;j++) {
                    if(arr1[i] == arr2[j]) {
                        System.out.println(arr1[i] + "-" + arr2[j]);
                    }
                }
            }
        } catch(InterruptedException e) {
            System.out.print(e);
        }
    }
}