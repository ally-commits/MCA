import java.io.RandomAccessFile;

public class RandomAcessF {
    public static void main(String args[]) throws Exception {
        RandomAccessFile rf = new RandomAccessFile("new.txt", "rw");

        // rf.close();
        System.out.println(rf.getFilePointer());
        rf.writeBytes("HELLOW WORLD");
        System.out.println(rf.readLine());
    }
}
