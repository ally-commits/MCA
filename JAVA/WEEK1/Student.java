import java.util.*;

class Student {

    public static void calculateTotal(int students[][],int n) {
        for(int i=0;i<n;i++) {
            int total = students[i][1] + students[i][2] + students[i][3]; 
            students[i][4] = total;
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(students[i][4] > students[j][4]) {
                    int temp = students[i][0];
                    students[i][0] = students[j][0];
                    students[j][0] = temp;

                    temp = students[i][1];
                    students[i][1] = students[j][1];
                    students[j][1] = temp;

                    temp = students[i][2];
                    students[i][2] = students[j][2];
                    students[j][2] = temp;

                    temp = students[i][3];
                    students[i][3] = students[j][3];
                    students[j][3] = temp;

                    temp = students[i][4];
                    students[i][4] = students[j][4];
                    students[j][4] = temp;
                }
            }
        }
        System.out.println("\nRegNo \t\tMarks1  Marks2  Marks3  Total");
        System.out.println("----------------------------------------------");
        for(int i=0;i<n;i++) {
            System.out.println(students[i][0] + "\t" + students[i][1] + "\t" + students[i][2] + "\t" + students[i][3] + "\t" + students[i][4]);
        }
    }

    public static void main(String args[]) {
        int students[][];
        int n;

        Scanner in = new Scanner(System.in);
        System.out.println("Enter the value of n:");
        n = in.nextInt();

        students = new int[n][5];

        for(int i=0;i<n;i++) {
            System.out.print("Enter regno:");
            students[i][0] = in.nextInt();
            System.out.print("Enter marks in 3 subjects:");
            students[i][1] = in.nextInt();
            students[i][2] = in.nextInt();
            students[i][3] = in.nextInt();
            students[i][4] = 0;
        }
        calculateTotal(students,n);

    }
}