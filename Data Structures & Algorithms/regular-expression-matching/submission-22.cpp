class Solution {
public:
    bool isMatch(string s, string p) {
        int n{static_cast<int>(s.size())}, m{static_cast<int>(p.size())};
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));

        auto back = [&](auto self, int i, int j) {
            if (i == n && j == m) {
                return true;
            }
            if (dp[i][j] != -1) return dp[i][j] ? true : false;
            dp[i][j] = 0;
            if (j + 1 <= m && p[j + 1] == '*') {
                if (i < n && (s[i] == p[j] || p[j] == '.')) {
                    dp[i][j] = dp[i][j] || self(self, i + 1, j);
                }
                dp[i][j] = dp[i][j] || self(self, i, j + 2);
            }
            else if (i < n && (s[i] == p[j] || p[j] == '.')) {
                dp[i][j] = dp[i][j] || self(self, i + 1, j + 1);
            }
            return dp[i][j] == 1 ? true : false;
        };
        return back(back, 0, 0);
    }
};
