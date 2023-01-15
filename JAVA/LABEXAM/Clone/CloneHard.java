class Dept1 implements Cloneable{
    String name;
    Dept1(String name) {
        this.name = name;
    }
    protected Dept1 clone() throws CloneNotSupportedException {
        return (Dept1) super.clone();
    }
}
class Emp1  implements Cloneable{
    String emp1Name;
    Dept1 d;

    Emp1(Dept1 d,String name) {
        this.d = d;
        this.emp1Name = name;
    }

    protected Emp1 clone() throws CloneNotSupportedException{
        Emp1 e = (Emp1) super.clone();
        e.d = (Dept1) d.clone();
        return e;
    }
}

class CloneHard {
    public static void main(String args[]) throws Exception {
        Dept1 d = new Dept1("Manager");
        Emp1 e1 = new Emp1(d,"Ally");
        Emp1 e2 = e1.clone();
        
        System.out.println(e1.d.name);
        e2.d.name = "CEO";
        System.out.println(e1.d.name);
    }
}