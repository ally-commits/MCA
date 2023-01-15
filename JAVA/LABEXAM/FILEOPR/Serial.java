import java.io.*;


class A implements Serializable{
    int a;
    transient int b;
    A(int a,int b) {
        this.a = a;
        this.b = b;
    }

    void display() {
        System.out.println("\nA=" + a);
        System.out.println("\nB=" + b);
    }
}
class Serial {
    public static void main(String args[]) throws Exception{
        A a1 = new A(10,20);
        A a2 = new A(20, 60);
        A a3 = new A(30, 80);
        A a4 = new A(40, 100);


        ObjectOutputStream f1 = new ObjectOutputStream(new FileOutputStream("replica/one.txt"));

        f1.writeObject(a1);
        f1.writeObject(a2);
        f1.writeObject(a3);
        f1.writeObject(a4);
        f1.close();

        ObjectInputStream f2 = new ObjectInputStream(new FileInputStream(("replica/one.txt")));
        A a;
        a = (A) f2.readObject();
        a.display();
        a = (A) f2.readObject();
        a.display();
        a = (A) f2.readObject();
        a.display();
        a = (A) f2.readObject();
        a.display();



    }
}