public class TEST {
    public static int findNum(int num) {
        String str = Integer.toString(num);
        int lastNum = Integer.parseInt(String.valueOf(str.charAt(str.length() - 1)));

        // System.out.println(lastNum);
        if(lastNum == 0) {
            return 1;
        } else {
            int newNum = num - lastNum;
            System.out.println(newNum);
            return (newNum - (lastNum * 5000)) / 5000;
        }
    }
    public static void main(String args[]) {
        System.out.println(findNum(5000));
        System.out.println(findNum(25003));
    }
}
