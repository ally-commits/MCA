import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;

class A implements Serializable {
    int a = 100;
    transient int b = 200;
}

public class ObjectStream {
    public static void main(String args[]) throws Exception{
        ObjectOutputStream output = new ObjectOutputStream(new FileOutputStream(("newFile.txt")));
        A a = new A();
        output.writeObject(a);


        ObjectInputStream input = new ObjectInputStream(new FileInputStream("newFile.txt"));
        A b = (A) input.readObject();

        System.out.print(b.a);

        System.out.print("\n");
    }
}
