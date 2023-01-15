public class TEST {
    public static int[] findNum(int arr1[], int arr2[]) {
        int arr[] = new int[];
        int toggle = 1;
        for(int i=0;i<n;i++) {
            if(toggle) {
                arr[i] = arr1[i];
            } else {
                arr[i] = arr2[i];
            }
        }
        return arr;
    }

    public static void main(String args[]) {
        int arr1[] = {1,2,3,5,6};
        int arr2[] = { 1, 2, 3, 5, 6 };
        System.out.println(findNum(arr1, arr2)); 
    }
}
