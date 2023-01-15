class A {
    private int a;
    private int b;
    static int c;

    class Nested {
        Nested() {
            System.out.println("NESTED");
        }
        void show() {
            System.out.println("A:" + a + "-B:" + b);
            // System.out.println("C:" + c);
        }
    }
    

    A() {
        System.out.println("A CLASS");
        Nested n = new Nested();
        n.show();
    }
}
class Nested {
    public static void main(String args[]) {
        A a = new A();
        A.Nested n = a.new Nested();
    } 
}

// s//Alwin
//newStr = s.append(" Crasta");
// String a = "ONE"
// String b = "ONEe"

//ONE
//ONE
//ONEe
//ALWIN
//ALWIN CRASTA