import java.util.ArrayList;
import java.util.*;

public class Pattern {
    public static void main(String args[]) {
        ArrayList<Integer> lengths = new ArrayList<Integer>();

        lengths.add(3);
        lengths.add(5);
        lengths.add(7);

        int n = Collections.max(lengths);

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                boolean printHash = false;

                if(i == n || j == n || i == 1 || j == 1) {
                    printHash = true;
                }
                if(lengths.contains(i) && j <= i) {
                    printHash = true;
                }
                if (lengths.contains(j) && i <= j) {
                    printHash = true;
                }

                if(printHash) {
                    System.out.print("#");
                } else {
                    System.out.print(" ");
                }
            }
            System.out.print("\n");
        }

    }
}
