import java.util.*;


class Test1 {
    public static void main(String args[]) {
        try {
            int a = 1 / 0;
            System.out.println("DONE");
        } catch(Exception e) {
            System.out.println(e.getMessage());
        }

        System.out.println("YES PROGRAM DOES NOT CRASH");
        try {
            Thread.sleep(100000);
        } catch(Exception e) {

        }
    }
}