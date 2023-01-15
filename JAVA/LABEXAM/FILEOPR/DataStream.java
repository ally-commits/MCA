import java.io.*;

public class DataStream {
    public static void main(String args[]) {
        try {
            DataOutputStream f1 = new DataOutputStream(new FileOutputStream("replica/one.txt"));
            
            f1.writeInt(10);
            f1.writeInt(100);
            f1.writeInt(1000);
            f1.writeInt(10000);
            f1.writeInt(100000);
            f1.writeDouble(100000.00);
            f1.writeChars("HELLO WORLD");
            f1.close();
            DataInputStream f2 = new DataInputStream(new FileInputStream("replica/one.txt"));

            System.out.println(f2.readInt());
            System.out.println(f2.readInt());
            System.out.println(f2.readInt());
            System.out.println(f2.readInt());
            System.out.println(f2.readInt());
            System.out.println(f2.readDouble());
            System.out.println(f2.readChar());

        } catch(Exception e) {

        }
    }
}
