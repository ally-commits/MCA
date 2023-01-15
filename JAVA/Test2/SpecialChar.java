class SpecialChar {
    public static void main(String args[]) {
        String str = "ABCDEFG";

        char ch[] = str.toCharArray();

        for(int i=0;i<str.length();i++)
            System.out.println(ch[i] + " " + (int) ch[i]);
    }
}