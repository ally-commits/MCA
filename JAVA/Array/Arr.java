public class Arr {
    public static void main(String args[]) {
        int arr[] = {1,2,3,4,5};
        int arr2[] = arr.clone();
        int arr3[] = arr;

        arr2[1] = 100;
        arr3[1] = 200;
        for(int x: arr) {
            System.out.println(x);
        }


        for(int x: arr2) {
            System.out.println(x);
        }


        for(int x: arr3) {
            System.out.println(x);
        }
        
    }
}
