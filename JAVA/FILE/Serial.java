import java.util.Scanner;
import java.io.*;

class Bank implements Serializable {
    String name;
    int age, accountNumber, balanceAmount;


    transient Scanner sn = new Scanner(System.in);

    void insertData()  {
        System.out.print("Enter Name:");
        name = sn.next();
        System.out.println("Enter Age,Account Number & Balance Amount:");
        age = sn.nextInt();
        accountNumber = sn.nextInt();
        balanceAmount = sn.nextInt();
    }

    void displayData() {
        System.out.print("\nName:" + name);
        System.out.print("\nAge:" + age);
        System.out.print("\nAccount Number:" + accountNumber);
        System.out.print("\nBalance Amount:" + balanceAmount);
    }
}

class Serial {
    public static void main(String args[])  {

        try {
            ObjectOutputStream output = new ObjectOutputStream(new FileOutputStream(("account_info.txt")));

            Scanner sn = new Scanner(System.in);
            System.out.println("Enter n value:");
            int n = sn.nextInt();

            for(int i=0;i<n;i++) {
                Bank b = new Bank();
                b.insertData();
                output.writeObject(b);
            }

            ObjectInputStream input = new ObjectInputStream(new FileInputStream(("account_info.txt")));

            System.out.print("Bank Details:");
            for (int i = 0; i < n; i++) {
                System.out.print(("\n------------------------"));
                Bank b;
                b = (Bank) input.readObject();
                b.displayData();
                System.out.print("\n");
            }

        } catch(Exception e) {
            System.out.print(e);
        }
    }
}
