class Solution {
public:
    bool isMatch(string s, string p) {
        int n{static_cast<int>(s.size())}, m{static_cast<int>(p.size())};
        vector<vector<bool>> dp(n + 1, vector<bool> (m + 1));
        dp[n][m] = true;
        for (int i{n}; i >= 0; --i) {
            for (int j{m}; j >= 0; -- j) {
                if (j + 1 < m && p[j + 1] == '*') {
                    if (i < n && (p[j] == '.' || p[j] == s[i]))
                        dp[i][j] = dp[i][j] || dp[i + 1][j];
                    dp[i][j] = dp[i][j] || dp[i][j + 2];
                }
                else if (i < n && (p[j] == '.' || p[j] == s[i])) {
                    dp[i][j] = dp[i][j] || dp[i + 1][j + 1];
                }
            }
        }
        return dp[0][0];
    }
};
