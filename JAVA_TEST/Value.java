public class Value {
    public static void main(String args[]) {
        int arr[] = {1,2,3,4};
        int max = 0;
        for(int i=0;i<arr.length;i++) {
            int resetCounter = i;
            int newArr[] = new int[4];

            for(int j=0;j<4;j++) {
                if (resetCounter == arr.length) {
                    resetCounter = 0;
                }
                newArr[j]= arr[resetCounter++];
            } 
            int value = (newArr[0] & newArr[1]) + (newArr[2] & newArr[3]);
            if(value > max) 
                max = value;
        }

        System.out.print(max);
    }
}
