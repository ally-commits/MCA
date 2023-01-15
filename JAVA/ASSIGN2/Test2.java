import java.util.*;


class Test2 {
    public static void main(String args[]) {

        int b = 10 / 0;
        try {
            int a = 1 / 0;
            System.out.println("DONE");
            
        } 
        catch (ArithmeticException e) {
            System.out.println(e.getMessage());
        } 

        catch (Exception e) {
            System.out.println(e.getMessage());
        }
        catch (Throwable e) {
            System.out.println(e.getMessage());
        } 
         
        finally {
            System.out.println("YES FINALLy");
        }
    }
}