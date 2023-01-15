import java.util.*;

class IntArrComp {
    int arr[] = new int[10];
    int n;

    Scanner s = new Scanner(System.in);

    IntArrComp() {}

    IntArrComp(int n) {
        this.n = n;
        System.out.print("Array Elements:");
        for(int i=0;i<n;i++) {
            arr[i] = s.nextInt();
        }
    }

    void display() {
        for(int i=0;i<n;i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
    void searchValue(int val) {
        int found = 0;
        for(int i=0;i<n;i++) {
            if(val == arr[i]) {
                found = 1;
                System.out.print("Found at location:" + i);
            }
        }
        if(found == 0)
            System.out.print("Not Found");
        System.out.println();
    }

    void compare(IntArrComp obj) {
        if(obj.n != n) {
            System.out.println("Not Equal");
        } else {
            int fount = 0;
            for(int i=0;i<n;i++) {
                if(arr[i] != obj.arr[i]) {
                    fount = 1;
                    System.out.println("Not Equal");
                }
            }
            if(fount == 0)
                System.out.print("Equal");
        }
    }
}

class IntArr {
    public static void main(String args[]) {
        IntArrComp obj1 = new IntArrComp(5);
        IntArrComp obj2 = new IntArrComp(5);

        obj1.display();
        obj1.searchValue(10);

        obj1.compare(obj2);
    }
}