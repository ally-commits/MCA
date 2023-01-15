import java.util.*;

class Simple {
    int a,b;

    Simple() {
        a = 10;
        b = 20;
    }

    Simple(int a,int b) {
        this.a = a;
        this.b = b;
    }
    Simple(Simple a) {
        this.a = a.a;
        this.b = a.b;
    }

    void display() {
        System.out.println("A:" + a);
        System.out.println("B:" + b);
    }
    void increment() {
        a++;
        b++;
    }

    void descrement() {
        a--;
        b--;
    }
}

class SimpleOne extends Simple {
    int c;

    SimpleOne() {
        super();
        c = 30;
    }
    SimpleOne(int a,int b,int c) {
        super(a,b);
        c = this.c;
    }
    SimpleOne(SimpleOne s) {
        super(s);
        this.c = s.c;
    }
    void display() {
        System.out.println("A:" + a);
        System.out.println("B:" + b);
        System.out.println("C:" + c); 
    }
    void increment() {
        a++;
        b++;
        c++;
    }
    void descrement() {
        a--;
        b--;
        c--;
    }
}

class SimpleClass {
    public static void main(String args[]) {
        SimpleOne s1 = new SimpleOne();
        SimpleOne s2 = new SimpleOne(1,2,3);
        SimpleOne s3 = new SimpleOne(s1);

        s1.increment();
        s2.increment();
        s3.increment();

        s1.display();
        s2.display();
        s3.display();

        s1.descrement();
        s2.descrement();
        s3.descrement();

        s1.display();
        s2.display();
        s3.display();
    }
}