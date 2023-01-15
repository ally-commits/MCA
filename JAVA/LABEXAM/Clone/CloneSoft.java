class Dept {
    String name;
    Dept(String name) {
        this.name = name;
    }
}
class Emp  implements Cloneable{
    String empName;
    Dept d;

    Emp(Dept d,String name) {
        this.d = d;
        this.empName = name;
    }

    protected Emp clone() throws CloneNotSupportedException{
        return (Emp) super.clone();
    }
}

class CloneSoft {
    public static void main(String args[]) throws Exception {
        Dept d = new Dept("Manager");
        Emp e1 = new Emp(d,"Ally");
        Emp e2 = e1.clone();
        
        System.out.println(e2.d.name);
        e2.d.name = "CEO";
        System.out.println(e2.d.name);
    }
}