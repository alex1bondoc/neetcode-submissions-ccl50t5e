class Solution {
    public int coinChange(int[] coins, int amount) {
        int[] dp = new int[amount + 1];
        java.util.Arrays.fill(dp, Integer.MAX_VALUE / 2);
        dp[0] = 0;
        for (int s = 1; s <= amount; s++) {
            for (int i :  coins) {
                if (s - i < 0) {
                    continue;
                }
                dp[s] = Math.min(dp[s], dp[s - i] + 1);
            }
        }
        return dp[amount] == Integer.MAX_VALUE /2  ? -1 : dp[amount];
    }
}
