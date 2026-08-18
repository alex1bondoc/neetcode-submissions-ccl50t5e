class Solution {
public:
    bool isMatch(string s, string p) {
        int n{static_cast<int>(s.size())}, m{static_cast<int>(p.size())};
        vector<vector<bool>> dp(n + 1, vector<bool> (m + 1));
        dp[n][m] = true;
        for (int i{n}; i >= 0; --i) {
            for (int j{m - 1}; j >= 0; --j) {
                bool firstMatch{i < n && (p[j] == s[i] || p[j] == '.')};
                if (j + 1 < m && p[j + 1] == '*') {
                    dp[i][j] = (firstMatch && dp[i + 1][j]) || dp[i][j + 2];
                }
                else {
                    dp[i][j] = firstMatch && dp[i + 1][j + 1];
                }
            }
        }
        return dp[0][0];
    }
};
