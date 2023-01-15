class GenericClass<T1,T2> {
    T1 member1;
    T2 member2;

    GenericClass(T1 t1,T2 t2) {
        System.out.println(t1.getClass().getName());
        System.out.println(t2.getClass().getName());
    }
}

class Gen2 {
    public static void main(String args[]) {
        GenericClass<Integer,String> a = new GenericClass<Integer,String>(50, "HELLO");
        GenericClass<String, Integer> b = new GenericClass<String,Integer>("HEY", 100);
    }
}