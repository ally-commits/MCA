class Func {

    int[] getArray() {
        int arr[] = new int[10];

        for(int i=0;i<arr.length;i++) 
            arr[i] = i * 100;

        return arr;
    }
    public static void main(String args[]) {
        int arr[] = new Func().getArray();

        for(int i=0;i<arr.length;i++) 
            System.out.println(arr[i]);
    }   
}