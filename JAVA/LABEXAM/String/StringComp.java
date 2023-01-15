class StringComp {
    public static void main(String args[]) {
        String arr[] = {"A","B","C","D"};

        for(String v: arr) {
            for(String a: arr) {
                if(v.compareTo(a) == 0) {
                    System.out.print(v + "=>" + a + "\n");
                }
            }
        }
        System.out.print("\n");




        String str = "Alwin Crasta";

        System.out.println(str.startsWith("Alwin"));
        System.out.println(str.endsWith("Crasta"));

        System.out.println(str.lastIndexOf("a"));

        System.out.println(str.contains("in"));

        System.out.println(str.replace("Crasta","Pasta"));

        System.out.println("  Alwin".trim());


        String strTime = "download.png";
        String strArr[] = strTime.split("\\.");


        for(String strA: strArr) {
            System.out.print(strA + " ");
        }
 
        System.out.println("".isEmpty());


        StringBuffer s = new StringBuffer("alwincrasta@Ally");
        System.out.println(s.append("<>"));
        System.out.println(s.reverse());
      
    }
}