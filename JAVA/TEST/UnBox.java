class UnBox {
    final int a;

    UnBox() {
        a = 10;
    }
    public static Integer unBox(Integer i) {
        return i;
    }
    public static void main(String args[]) {
        // Integer intValue = new Integer(10);
        UnBox b = new UnBox();
        // int a = unBox(intValue);
        // System.out.println("VALUE:" + a);
    }
}