class NonGen {
    Object ob;

    NonGen(Object o) {
        ob = o;
    }

    Object getOb() {
        return ob;
    }
}

class Obj {
    public static void main(String args[]) {
        NonGen iob = new NonGen(10);
        int v = (Integer) iob.getOb();


        System.out.println("VALUE V:" + v);
    }
}