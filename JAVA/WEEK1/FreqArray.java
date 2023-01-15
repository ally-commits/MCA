import java.util.Scanner;

class FreqArray {
    public static void main(String args[]) {
        int arr[],freq[][];
        int n;

        Scanner s = new Scanner(System.in);

        System.out.println("Enter value of n:");
        n = s.nextInt();

        arr = new int[n];
        freq = new int[n][2];

        System.out.println("Enter Array Elements:");
        for(int i=0;i<n;i++) {
            arr[i] = s.nextInt();
        }
        int count = 0;
        for(int i=0;i<n;i++) {
            int found = 0;
            for(int j=0;j<count;j++) {
                if(arr[i] == freq[j][0]) {
                    freq[j][1]++;
                    found = 1;
                }
            }
            if(found == 0) {
                freq[count][0] = arr[i];
                freq[count][1] = 1;
                count++;
            }
        }


        System.out.println();
        for(int i=0;i<count;i++) {
            System.out.println(freq[i][0] + "=>" + freq[i][1]);
        }
        System.out.println();
        
    }
}