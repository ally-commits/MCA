class A implements Cloneable {
    int a;
    A(int a) {
        this.a = a;
    } 
    void display() {
        System.out.println("DISP:" + a);
    }
    
    public Object clone() throws CloneNotSupportedException {
        // A cloned = (A) super.clone(); 
        return  super.clone();
    }
}

public class One {
    public static void main(String[] args) {
        try {
            A a = new A(1);
            A b = (A) a.clone();
    
            a.a = 20;
            b.a = 30;

            a.display();
            b.display();
        } catch(CloneNotSupportedException e) {
            System.out.print(e);
        }
    }
}