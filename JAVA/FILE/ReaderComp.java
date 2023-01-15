import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class ReaderComp {
    public static void main(String args[]) throws IOException{
        // FileReader reader = new FileReader("one.txt");

        // System.out.println((char) reader.read());
        // System.out.println((char) reader.read());
        // System.out.println((char) reader.read());
        // System.out.println((char) reader.read());
        // System.out.println((char) reader.read());



        // FileWriter writer = new FileWriter("two.txt",true);
        // byte b = 10;
        

        DataOutputStream output =  new DataOutputStream(new FileOutputStream("one.txt"));

        output.writeBytes("HELLO THERE");

        DataInputStream input = new DataInputStream((new FileInputStream("one.txt")));
        System.out.println(input.readAllBytes());
        // writer.write(70);

        // FileReader fin = new FileReader("one.txt");
        // FileWriter fwrite = new FileWriter("two.txt");
        // Scanner sn = new Scanner(System.in);

        // try {
        //     int input;
        //     do {
        //         input = fin.read();
        //         if (input != -1) {
        //             fwrite.write((char) input);
        //         }
        //     } while (input != -1);

        // } catch (Exception e) {
        //     System.out.println("I/O Error: " + e);
        // } finally {
        //     try {
        //         if (fwrite != null)
        //             fwrite.close();
        //         if (fin != null)
        //             fin.close();
        //     } catch (IOException e2) {
        //         System.out.println("Error Closing Output File");
        //     }
        // }
    }
}
