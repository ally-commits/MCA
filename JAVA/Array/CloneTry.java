class A {
    int a = 100;
    void display() {
        System.out.print(a);
    }
}

public class CloneTry {
    public static void main(String args[]) throws CloneNotSupportedException{
        A a= new A();
        A b = a.clone();
    }
}
