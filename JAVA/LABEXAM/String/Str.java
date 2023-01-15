class Str {
    public static void main(String args[]) {
        String s1 = "Welcome to javao";
        String s2 = s1;
        String s3 = new String("Weloooome to java");

        System.out.println(s2 == s3);
        System.out.println(s1.compareTo(s2));
        System.out.println(s1.equals(s3));
        System.out.println(s1.lastIndexOf('a'));
        System.out.println(s3.lastIndexOf("o",5));
        System.out.println(s2.substring(5,11));
    }
}