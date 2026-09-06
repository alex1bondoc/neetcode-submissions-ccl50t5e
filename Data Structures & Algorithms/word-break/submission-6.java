class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        boolean[] dp = new boolean[s.length() + 1];
        int maxLen = 0;
        Set<String> set = new HashSet<>();
        for (String word : wordDict) {
            set.add(word);
            maxLen = Math.max(maxLen, word.length());
        }
        dp[s.length()] = true;
        int n = s.length();
        for (int i = n - 1; i >= 0; i--) {
            for (int r = i + 1; r <= i + maxLen && r <= n; ++r) {
                System.out.println(s.substring(i, r));
                if (set.contains(s.substring(i, r))) {
                    dp[i] = dp[i] || dp[r];
                }
            }
        }
        return dp[0];
    }
}
