

import java.io.*;
import java.util.*;

public class CopyFile {
    public static void main(String args[]) throws FileNotFoundException,IOException {
        
        Scanner sn = new Scanner(System.in);

        FileReader fin = new FileReader("one.txt");
        FileWriter fwrite = new FileWriter("copy.txt");
        try {
            int input;
            do {
                input = fin.read();
                if (input != -1) {
                    fwrite.write((char) input);
                }
            } while (input != -1);

        } catch (Exception e) {
            System.out.println("I/O Error: " + e);
        } finally {
            try {
                if (fwrite != null)
                    fwrite.close();
                if (fin != null)
                    fin.close();
            } catch (IOException e2) {
                System.out.println("Error Closing Output File");
            }
        }

    }
}