import java.util.*;

class CustomException extends Exception {
    CustomException(String msg) {
        super(msg);
    }
}

class SplitOperation {
    public static void main(String args[]) {
        String strArr[] = new String[20];
        Scanner sn = new Scanner(System.in);

        ArrayList<String> strExtension = new ArrayList<String>();
        int n;
        System.out.println("Enter the value of n:");
        n = sn.nextInt();

        int maxLength = 0;
        System.out.println("Enter String");
        for(int i=0;i<n;i++) {
            strArr[i] = sn.next();
            int max = strArr[i].lastIndexOf(".");
            String extension = strArr[i].substring(max);
            strExtension.add(extension);
            
            if(max > maxLength) {
                maxLength = max;
            }
        }

        for(int i=0;i<n;i++) {
            int max = strArr[i].lastIndexOf(".");
            String sliceStr = "00000000000000".substring(0,maxLength - max);
            strArr[i] = sliceStr + strArr[i];
            System.out.println(strArr[i]);
        }
    }
}