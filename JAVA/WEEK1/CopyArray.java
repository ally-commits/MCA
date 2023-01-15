import java.util.*;

class CopyArray {
    public static void main(String args[]) {
        int arr1[],arr2[];
        int n;

        Scanner sn = new Scanner(System.in);

        System.out.println("Enter n value:");
        n = sn.nextInt();
        arr1 = new int[n];
        arr2 = new int[n];

        System.out.println("Enter Array Elements:");
        for(int i=0;i<n;i++) {
            arr1[i] = sn.nextInt();
            arr2[n-(i+1)] = arr1[i];
        } 

        System.out.println("\n");
        for(int i=0;i<n;i++) {
            System.out.print(arr2[i] + " ");
        }
        System.out.println("\n");
    }
}