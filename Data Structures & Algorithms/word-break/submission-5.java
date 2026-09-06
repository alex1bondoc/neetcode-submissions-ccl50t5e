class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        boolean[] dp = new boolean[s.length() + 1];
        dp[s.length()] = true;
        int n = s.length();
        for (int i = n - 1; i >= 0; i--) {
            for (String str : wordDict) {
                if (i + str.length() - 1 < n) {
                    if (str.equals(s.substring(i, i + str.length()))) {

                        dp[i] = dp[i] || dp[i + str.length()];
                    }
                }
            }
        }
        for (boolean i : dp) {
            System.out.print(i + " ");
        }
        return dp[0];
    }
}
