import java.util.*;
import java.text.*;

class Sum {

    void computeMatrix(double arr[][], int n,int m) {
        double sum = 0;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                sum += arr[i][j] * arr[i][j];
            }
        }
        sum = Math.sqrt(sum);
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                arr[i][j] =  arr[i][j] / sum;
            } 
        }
    }

    void display(double arr[][], int n,int m) {
        DecimalFormat df = new DecimalFormat("#0.00");
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                System.out.print(df.format(arr[i][j]) + " ");
            }
            System.out.print("\n");
        } 
    }

    public static void main(String args[]) {
        double arr[][];
        int n,m;

        Scanner sn = new Scanner(System.in);

        System.out.println("Enter Row and Col:");
        n = sn.nextInt();
        m = sn.nextInt();

        System.out.println("Enter Matrix");

        arr = new double[n][m];


        for(int i=0;i<arr.length;i++) {
            for(int j=0;j<arr[i].length;j++) {
                arr[i][j] = sn.nextInt();
            }
        }

        Sum sm = new Sum();
        sm.computeMatrix(arr,n,m);
        sm.display(arr,n,m);
    }
}