import java.util.*;

class VectorMain {
    public static void main(String args[]) {
        Vector<String> v = new Vector<String>(5,2);

        v.addElement("Alwin");
        v.addElement("Melwin");
        v.addElement("Royal");
        v.addElement("Sharon");
        v.addElement("Nix");

        v.add("Dix");
        v.insertElementAt("Ally", 0);

        
        System.out.println(v);
        v.remove("Ally");

        v.removeElementAt(1);
        System.out.println(v.firstElement());
        System.out.println(v.lastElement());
        System.out.println(v.contains("Alwin"));


        System.out.println(v);
    }
}