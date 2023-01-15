import java.io.*;

public class InputStream {
    public static void main(String args[])throws IOException {
        

        byte bytes[] = new byte[100];
        FileInputStream reader = new FileInputStream("one.txt");

        reader.read(bytes);
        
        for(int i=0;i<bytes.length;i++) {
            System.out.print((char) bytes[i]);
        }
        // System.out.println(bytes);


        System.out.print(reader.available()+"\n");
        System.out.print(reader.skip(10)); 



        File f1 = new File("/Users/alwincrasta/MCA/JAVA/FILE/one.txt");
        FileOutputStream writer = new FileOutputStream(f1,true);

        writer.write('a');

        writer.write(bytes);
        

    }
}
