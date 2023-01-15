abstract class SmartPhone {
    abstract void openAppStore();
} 

class Iphone extends SmartPhone {
    void openAppStore() {
        ///OPEN APP Store
    }
}
class Android extends SmartPhone {
    //OPEN PLAY STORE
} 
class Black extends SmartPhone {
    //OPEN VLAKC
}

class B extends AbsNew {
    void test() {
        System.out.println("ONE");
    }
}

class Abs {
    public static void main(String args[]) {
        AbsNew a[10] = {
            new Iphone(),
            new Black()
        }; 
        
        B b = new B();
        
        a = b;
        a.test();
    }
}