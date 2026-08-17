class Solution {
public:
    int numDistinct(string s, string t) {
        int n{static_cast<int>(s.size())}, m{static_cast<int>(t.size())};
        
        vector<int> dp(m + 1);
        dp[0] = 1;
        for (int i{1}; i <= n; ++i) {
            vector<int> newDp(m + 1);
            newDp[0] = 1;
            for (int j{1}; j <= m; ++j) {
                newDp[j] = dp[j];
                if (s[i - 1] == t[j - 1]) newDp[j] += dp[j - 1];
            }
            dp = newDp;
        }
        // {
        //     i == n && j == m return 1
        //     if i > n || j > m return 0
        //     return max(self(i + 1, j), self(i, j + 1))

        // }
        return dp[m];
    }
};
