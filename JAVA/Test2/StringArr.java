class StringArr {
    public static void main(String args[]) {
        String str1 = new String(" ABCDEfGHIAJK");
        String str2 = new String("CDEFGHIJK");


        System.out.println(str1.charAt(10));
 
        System.out.print(str1.compareTo("ONE"));

        System.out.println(str1.compareToIgnoreCase("ONE"));

        System.out.println(str1.concat("ONE"));

        System.out.println(str1.contains("ONE"));

        System.out.println(str1.endsWith("K"));
        System.out.println(str1.equals("ABCDEFGHIJK"));


        System.out.println(str1.getBytes());
        System.out.println(str1.toCharArray());

        System.out.println(str1.indexOf("D"));

        System.out.println(str1.replace("A","V"));
        System.out.println(str1.replaceFirst("A","V"));
        System.out.println(str1.replaceAll("A","V"));



        // System.out.print(str1.split(""));

        System.out.println(str1.startsWith("A"));

        System.out.println(str1.substring(2,5));

        System.out.println(str1.toUpperCase());
        System.out.println(str1.toLowerCase());

        System.out.println(str1.trim());

    }
}