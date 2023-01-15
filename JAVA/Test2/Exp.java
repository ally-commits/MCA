public class Exp {
    public static void main(String args[]) {
        try {
            int a = 0 / 10;
        } catch(RuntimeException e) {
            System.out.println(e);
        }

        int b = 5 / 0;
    }
}
