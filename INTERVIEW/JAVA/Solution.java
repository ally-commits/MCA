class Solution {
    public static int maxProfit(int[] prices) {
        int profit = 0;
        int n = prices.length;
        int brought = 100000000;
        boolean broughtValue = false;

        for (int i = 0; i < n - 1; i++) {
            if (brought < prices[i] && (prices[i] > prices[i + 1] || i == n-2)) {
                profit += prices[i] - brought;
                brought = 1000000;
                broughtValue = false;
            } else if (prices[i] < prices[i + 1] && broughtValue == false) {
                brought = prices[i];
                broughtValue = true;
                System.out.println("CONTNET");
            }
        }
        return profit;
    }

    public static void main(String args[]) {
        int arr[] = {1,2,3,4,5};
        System.out.println((maxProfit(arr)));
    }
}