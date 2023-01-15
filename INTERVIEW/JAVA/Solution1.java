class Solution1 {
    public static int pivotIndex(int[] nums) {
        int index = -1;
        int n = nums.length;

        for (int i = 0; i < n; i++) {
            int leftSum = 0;
            int rightSum = 0;

            for (int j = 0; j < i; j++) {
                leftSum += nums[j];
            }
            for (int j = i + 1; j < n; j++) {
                rightSum += nums[j];
            }

            System.out.println(leftSum + ":" + rightSum)    ;
            if (leftSum == rightSum)
                index = i;
        }

        return index;
    }
    public static void main(String args[]) {
        int arr[] = {1,7,3,6,5,6};
        System.out.println(pivotIndex(arr));
    }
}