interface A {
    int a = 10;
 
    void display();
    void test();
}
abstract class B implements A{
    public void display() {
        System.out.print("ONE" + a);
    }
}
public class Code7 {
    
}
