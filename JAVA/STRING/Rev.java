import java.util.*;
import java.util.regex;

class Rev {
    public static void main(String args[]) {
        int n = 4;
        Scanner sn = new Scanner(System.in);

        System.out.println("Enter value of n:");
        // n = sn.nextInt();

        String str[] = {"one.jpg","two.jpg","three.jpg","four.jpg"};
        System.out.println("Enter String Array:");
        for(int i=0;i<n;i++) {
            // str[i] = sn.next();
        }

        int maxLen = 0;
        for(int i=0;i<n;i++) {
            // System.out.println(str[i]);
            String newStr[] = str[i].split(Pattern.quote("[.]"));
            // System.out.println(newStr[0]);

            // for(int j=0;j<newStr.length;j++) 
            //     System.out.print(newStr[j] + ".");
            if(newStr[0].length() > maxLen) {
                maxLen = newStr[0].length();
            } 
        }
        for(int i=0;i<n;i++) {
            String newStr[] = str[i].split(Pattern.quote("."));
            String appendString = "";
            for(int j=0;j<maxLen - newStr[0].length();j++) {
                appendString += "0";
            }
            str[i] = appendString + str[i];

            System.out.println(str[i]);
            // System.out.println(appendString);
        }

        // System.out.print("MAX:" + maxLen);
        
    }
}