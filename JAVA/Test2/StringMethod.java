class StringMethod {
    public static void main(String args[]) {
        StringBuilder strA = new StringBuilder("Hello World");

        StringBuffer strB = new StringBuffer("");
        strB.setLength(strA.length());

        // String strS = new String("Hello World");
        // strB.setCharAt(1,'c');
        // System.out.println(strB.reverse());
        // int count =0;
        // for(int i=strA.length()-1;i>=0;i--) {
        //     strB.setCharAt(count++,strA.charAt(i));
        // }

        // System.out.println(strB);
        String strC = new String("Hey There");
        String strD = new String("Hey There");
        System.out.println(strC.equalsIgnoreCase(strD));

        char ch[] = strC.toCharArray();


        System.out.println(ch[0]);
    }
}