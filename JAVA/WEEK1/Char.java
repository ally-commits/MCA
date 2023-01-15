import java.util.*;



class Char {
    public static void charModify(char charArr[]) {
        int count = 0;
        for(int i=0;i<charArr.length;i++) {
            if(i % 5 == 0) {
                charArr[i + count] = (int) charArr[i + count];
                if((int) charArr[i] < 100) {
                    count += 2;
                } else {
                    count += 3;
                }
            }
        }


        System.out.println(charArr);
    }
    public static void main(String args[]) {
        char charArr[];

        charArr = new char[20];
        Scanner sn = new Scanner(System.in);

        charArr = sn.nextLine().toCharArray();

        charModify(charArr);   
    }
}