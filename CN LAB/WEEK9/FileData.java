import java.io.*; 

public class FileData {
    public static void main(String args[]) throws Exception{
        File file = new File("one.txt");
        FileInputStream f1 = new FileInputStream(file);

        byte[] b = new byte[(int) file.length()];

        f1.read(b);
        String str = new String(b, "UTF-8");

        System.out.println(str);


        File file2 = new File("five.txt");
        FileOutputStream f2 = new FileOutputStream(file2);
 
        f2.write(str.getBytes());


    }
}
