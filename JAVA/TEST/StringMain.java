 
class Main{
    public static void main(String args[]) {
        StringBuffer str1 = new StringBuffer(20);
        StringBuffer str2 = new StringBuffer("Hello World");

        str2.setLength(1);
        
        str2.append("HEY THERE");
        System.out.println(str1.capacity());  
        System.out.println(str2.capacity());
        
        
        System.out.println("STR1:" + str1);
        System.out.println("STR2:" + str2);

        str2.reverse();

        System.out.println("STR2:" + str2);


        str2.setCharAt(1,'A');

        System.out.println("STR2:" + str2);

        String str = str2.substring(1,10);
        System.out.println(str);
        System.out.println("STR2:" + str2);


        // str2.setLength(30);
        System.out.println(str2.capacity());
        str2.trimToSize();
        System.out.println(str2.capacity());


        str2.insert(2," like ");
        System.out.println("STR2:" + str2);


        str2.replace(3,10," like ");
        System.out.println("STR2:" + str2);

        StringBuffer str3 = new StringBuffer("abcabcabc");
        System.out.println("STR2:" + str3.indexOf("b"));
        System.out.println("STR2:" + str3.lastIndexOf("b"));
    }
    
}