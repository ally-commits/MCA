class GenericClass<T> {
    T member1;

    GenericClass(T t) {
        System.out.println(t.getClass().getName());
    }
}

class Gen {
    public static void main(String args[]) {
        GenericClass<Integer> a = new GenericClass<Integer>(50);
        GenericClass<String> b = new GenericClass<String>("HEY");
    }
}