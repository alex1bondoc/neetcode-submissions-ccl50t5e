class Solution {
public:
    bool isMatch(string s, string p) {
        int n{static_cast<int>(s.size())}, m{static_cast<int>(p.size())};
        vector<vector<bool>> dp(n + 1, vector<bool> (m + 1));
        for (int i{}; i <= m; ++i) {
            dp[n][i] = true;
        }
        auto back = [&](auto self, int i, int j) {
            if (i == n && j == m) return true;
            if (i > n || j > m) return false;
            bool res{false};
            if (dp[i][j] != -1) return dp[i][j] == 1 ? true : false;
            if (j < m && p[j + 1] == '*' ) {
                if (i == n || s[i] == p[j] || p[j] == '.')
                    res = res || self(self, i + 1, j);
                res = res || self(self, i, j + 2);
            }
            else if (p[j] == '.' || s[i] == p[j]) {
                res = res || self(self, i + 1, j + 1);
            }
            dp[i][j] = res ? 1 : 0;
            return res;
        };
        for (int i{n - 1}; i >= 0; --i) {
            for (int j{m - 1}; j >= 0; -- j) {
                if (p[j] == '*') continue;
                if (p[j + 1] == '*') {
                    int k{i};
                    if (s[k] == p[j] || p[j] == '.')
                        dp[i][j] = dp[i][j] || dp[i + 1][j];
                    dp[i][j] = dp[i][j] || dp[i][j + 2];
                }
                else if (p[j] == '.' || p[j] == s[i]) {
                    dp[i][j] = dp[i][j] || dp[i + 1][j + 1];
                }
            }
        }
        for (int i{};  i <= n; ++i, std::cout << std::endl) {
            for (int j{}; j <= m; ++j) {
                std::cout << dp[i][j] << " ";
            }
        }
        return dp[0][0];
    }
};
