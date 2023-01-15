// import packy.Test1;

// class TestNew{
//     TestNew() {
//         // display();
//         Test1 t1 = new Test1();
//         // t1.display();
//     }
//     // public static void main(String args[]) {
         
//     // }
// }

// class TestTwo {
//     public static void main(String args[]) {
//         TestNew t = new TestNew();
//     }
// }


interface One {
    void test1();
    void test2();
    void test3();
}

abstract class A implements One {
    public void test1() {
        System.out.print("1");
    }
    public void test2() {
        System.out.print("2");
    }

    void test4() {
        System.out.print("4");
    };
}
class AA extends A {
    public void test3() {
        System.out.print("2");
    }
}

class TestTwo {
    public static void main(String args[]) {
        AA a = new AA();
        a.test1();
        a.test2();
        a.test3();
        a.test4();
    }
}