public class Ash {
    public static void main(String args[]) {
        int n = 3;
        for(int i=0;i<n;i++) {
            for(int j=0;j<=i;j++) {
                System.out.print(i + 1);
                if(j != i)
                    System.out.print("*");
            }
            System.out.print("\n");
        }
        for (int i = n; i > 0; i--) {
            for (int j = i; j > 0; j--) {
                System.out.print(i);
                if (j > 1)
                    System.out.print("*");
            }
            System.out.print("\n");
        }
    }
}   
