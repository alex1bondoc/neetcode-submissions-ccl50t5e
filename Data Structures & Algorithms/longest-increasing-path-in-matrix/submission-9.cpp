class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n{static_cast<int>(matrix.size())}, m{static_cast<int>(matrix[0].size())};
        vector<vector<int>> dp(n, vector<int> (m));
        int res{};
        auto dfs = [&](auto self, int i, int j, int prev) {
            if (i < 0 || i >= n || j < 0 || j >= m || matrix[i][j] <= prev) return -1;

            if (dp[i][j] != 0) return dp[i][j];
            dp[i][j] = 1;
            dp[i][j] = max(dp[i][j], self(self, i + 1, j, matrix[i][j]) + 1);
            dp[i][j] = max(dp[i][j], self(self, i - 1, j, matrix[i][j]) + 1);
            dp[i][j] = max(dp[i][j], self(self, i, j + 1, matrix[i][j]) + 1);
            dp[i][j] = max(dp[i][j], self(self, i, j - 1, matrix[i][j]) + 1);
            return dp[i][j];
        };
        for (int i{}; i < n; ++i) {
            for (int j{}; j < m; ++j) {
                res = max(res, dfs(dfs, i, j, -1));
            }
        }
        return res;
    }
};
