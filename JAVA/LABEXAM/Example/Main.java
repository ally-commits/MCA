import java.util.*;

class Thread1 extends Thread {
    int arr[][];
    int sumArr[];
    Thread1(int arr[][]) {
        this.arr = arr;
        sumArr = new int[arr.length];
        start();
    }
    public void run() {
        for(int i=0;i<arr.length;i++) {
            sumArr[i] = 0;
            for(int j=0;j<5;j++) {
                sumArr[i] += arr[i][j];
            }
        }
    }

    void display() {
        System.out.println("\nTotal For Each Emp");
        for(int i=0;i<arr.length;i++) {
            System.out.println("Emp " + (i+1) + ":" + sumArr[i]);
        }
        System.out.println("\n");
    }
}

class Thread2 extends Thread {
    int arr[][];
    int everyDayWork[] = new int[5];
    Thread2(int arr[][]) {
        this.arr = arr;
        start();
    }
    public void run() {
        for(int i=0;i<arr.length;i++) {
            for(int j=0;j<5;j++) {
                everyDayWork[j] += arr[i][j];
            }
        }
    }
    void display() {
        String strArr[] = {"Mon","Tue","Wed","Thu","Fri"};

        System.out.println("\nWork of Emp based on days");
        for(int i=0;i<5;i++) {
            System.out.println(strArr[i] + "-"+  everyDayWork[i]);
        }
        System.out.println("\n");
    }
}

class Thread3 extends Thread {
    int arr[][];
    int empBasedOnWork[][] = new int[5][4];
    
    Thread3(int arr[][]) {
        this.arr = arr;
        start();
    }
    public void run() {
        for(int i=0;i<arr.length;i++) {
            int minWorkDay = 100;
            int minWorkHours = 100;
            int maxWorkDay = 0;
            int maxWorkHours = 0;
            int totalWorkHours = 0;
            
            for(int j=0;j<5;j++) {
                if(arr[i][j] >= maxWorkHours) {
                    maxWorkHours = arr[i][j];
                    maxWorkDay = j;
                } 
                if(arr[i][j] <= minWorkHours) {
                    minWorkHours = arr[i][j];
                    minWorkDay = j;
                }
                totalWorkHours += arr[i][j];
            }
            empBasedOnWork[i][0] = minWorkDay;
            empBasedOnWork[i][1] = minWorkHours;
            empBasedOnWork[i][2] = maxWorkDay;
            empBasedOnWork[i][3] = maxWorkHours;
            arr[i][5] = totalWorkHours;
            arr[i][6] = i;
        }
    }
    void display() {
        String strArr[] = {"Mon","Tue","Wed","Thu","Fri"};
        System.out.println("\nMin and Max Work Of emp");
        for(int i=0;i<arr.length;i++) {
            System.out.print("\nEmp-" + (i+1) + "  MIN WORK DAY:" + strArr[empBasedOnWork[i][0]] + "  MIN WORK HOURS:" + empBasedOnWork[i][1]);
            System.out.print("  MAX WORK DAY:" + strArr[empBasedOnWork[i][2]] + "  MAX WORK HOURS:" + empBasedOnWork[i][3] + "\n");
        }
        System.out.println("\n");
    }

}

class Thread4 extends Thread {
    int arr[][]; 
    Thread4(int arr[][]) {
        this.arr = arr;
        start();
    }
    public void run() {
        for(int i=0;i<arr.length;i++) {
            for(int j=0;j<arr.length;j++) {
                if(arr[i][5] > arr[j][5]) {
                    int newArr[] = arr[i];
                    arr[i] = arr[j];
                    arr[j] = newArr;
                }
            }
        }
    }

    public void display() {
        for(int i=0;i<arr.length;i++) {
            System.out.print("\nEMP: " + (arr[i][6]+1) + " HOURS " + arr[i][5]);
        }
    }

}

class Main {
    public static void main(String args[]) {
        int n;
        Scanner sn = new Scanner(System.in);
        System.out.print("Enter number of emp:");
        n = sn.nextInt();

        int arr[][] = new int[n][7];
        for(int i=0;i<n;i++) {
            for(int j=0;j<5;j++) {
                arr[i][j] = sn.nextInt();
            }
        }

        Thread1 t1 = new Thread1(arr);
        Thread2 t2 = new Thread2(arr);
        Thread3 t3 = new Thread3(arr);
        Thread4 t4 = new Thread4(arr);


        t1.display();
        t2.display();
        t3.display();
        t4.display();

        System.out.println("\n");
    }
}