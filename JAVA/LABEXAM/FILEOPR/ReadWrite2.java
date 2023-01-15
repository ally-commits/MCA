import java.io.FileWriter;

public class ReadWrite2 {
    public static void main(String args[]) throws Exception{
        try {
            FileWriter f1 = new FileWriter("replica/new.txt",true);

            f1.write("\nHEY THERE SOME CONTENT CAN BE SEEN HERE");
            f1.append("\nHEY THERE SOME CONTENT CAN BE SEEN HERE");
            f1.close();
        } catch(Exception e) {
            System.out.print(e);
        }
    }
}
