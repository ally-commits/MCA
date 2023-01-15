import java.io.*;

public class ByteStream {
    public static void main(String args[]) throws Exception{
        FileInputStream file1 = new FileInputStream(new File("files/4.txt"));
        FileOutputStream file2 = new FileOutputStream(new File("files/600.txt"));

        int input = file1.read();
        while(input != -1){
            System.out.print((char) input + "-");
            System.out.print(file1.available() + " ");
            // file2.write((byte) 65);
            input = file1.read();
        }

        System.out.println("\n");
    }
}
