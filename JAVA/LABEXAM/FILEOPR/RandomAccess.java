import java.io.*;

public class RandomAccess {
    public static void main(String args[]) throws Exception {
        RandomAccessFile f1 = new RandomAccessFile("replica/newFile.txt","rw");

        // f1.writeBytes("HEY THERE LINE 1\n");
        // f1.writeBytes("HEY THERE LINE 2\n");
        // f1.writeBytes("HEY THERE LINE 3\n");
        // f1.writeBytes("HEY THERE LINE 4\n");
        // f1.writeBytes("HEY THERE LINE 5\n");
        // f1.writeBytes("HEY THERE LINE 6\n");
        // f1.writeBytes("HEY THERE LINE 7\n");
        
        f1.writeInt(10);
        f1.writeInt(20);
        f1.writeInt(30);
        f1.writeInt(40);
        f1.seek(0);
        System.out.println(f1.readInt());
        System.out.println(f1.getFilePointer());
        f1.seek(4*(4-1));
        System.out.println(f1.readInt());

    }
}
