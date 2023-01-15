class A {
    int a;
    // protected void display1() {
    //     System.out.print("A");
    // }
    A() {
        System.out.print("B");
    }
}
 class B extends A {
    B() {
        System.out.print("A");
    }
    // void display(int m) {
        // display1();
        // this.a = m;
        // System.out.print("B" + a);
    // }
}

class Int {
    public static void main(String args[]) {
        // A  a;
        B b = new B();

        // a = b;
        // b.display(3020);
    }
}

// public class Alpha {
//     int a;
// }
