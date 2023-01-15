class A {
    int a = 10;
    private int m = 1000;
    void test() {
        System.out.println("A");
    }
}

class B extends A {
    int a = 20;
    B() {
        // System.out.println("ONE");
        super();
    }
    void test() {
        System.out.println("B");
        super.a = 20;
    }
    
}

class C extends B {
    void test() {
        System.out.println("M="+ super.m);
    }
}

class Try {
    public static void main(String args[]) {
        // A a = new A();
        C b = new C();

        b.test();
        System.out.println(b.a);
        // C c = new C();

        // A aRef;
        // aRef = b;
        // aRef.test();
        // aRef.one();
        // aRef.a = 10;

        // aRef = b;
        // aRef.test();
        // aRef = c;
        // aRef.test();
    }   
}