class Autobox {
    public static void autoBox(Integer i) {
        System.out.println("VALUE:" + i);
    }
    public static void main(String args[]) {
        int i = 10;
        Integer intValue = new Integer(20);

        int a = intValue;
        autoBox(i);

        System.out.println("ONE");
    }
}