class A {
    void display() {
        System.out.print("A DISPLAY");
    }
}
class B extends A {
    void display() {
        System.out.print("B DISPLAY");
    }
}

class C {
    public static void main(String args[]) {
        B b = new B();
        b.display();
    }
}