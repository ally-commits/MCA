import java.util.*;

class Arr {
    public static void main(String args[]) {
        int n,m;

        Scanner sn = new Scanner(System.in);
        System.out.println("Enter n and m:");
        
        n = sn.nextInt(); 
        int[][] arr = new int[n][];


        for(int i=0;i<n;i++) {
            System.out.println("Enter 1st row size:");
            int s;
            s = sn.nextInt();
            arr[i] = new int[s+1];
            arr[i][0] = s;
            for(int j=1;j<=s;j++) {
                arr[i][j]= sn.nextInt();
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=1;j<=arr[i][0];j++) {
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }

    }
}