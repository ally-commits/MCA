// class A extends Exception {
//     String s;
//     A(String s) {
//         super(s);
//         this.s = s;    
//     }
// }

class Test5 { 
    public static void main(String args[]) {
        try {
            String str = null;
            int a = str.length();
        } 
        catch(ArithmeticException e) {
            System.out.println("EXCEPTION" + e);    
        } 
        finally {
            System.out.println("FINALLY");
        }
        System.out.println("TEST 5");
    }
}
 