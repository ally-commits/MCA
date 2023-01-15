abstract class A {
    abstract void method1();
    abstract void method2();
}

class B extends A {
    public void method1() {
        System.out.print("\nHEY THERE 1");
    }
    public void method2() {
        System.out.print("\nHEY THERE 2");
    }
}
class AbstractMain {
    public static void main(String args[]) {
        B b = new B();
        b.method1();
        b.method2();
    }
}