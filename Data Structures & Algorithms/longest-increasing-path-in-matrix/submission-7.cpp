class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        int res{};
        auto dfs = [&](auto self, int i, int j, int number) {
            if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || matrix[i][j] <= number) return -1;
            if (dp[i][j]) {
                return dp[i][j];
            }
            dp[i][j] = 1;
            dp[i][j] = max(dp[i][j],self(self, i + 1, j, matrix[i][j]) + 1);
            dp[i][j] = max(dp[i][j],self(self, i - 1, j, matrix[i][j]) + 1);
            dp[i][j] = max(dp[i][j],self(self, i, j + 1, matrix[i][j]) + 1);
            dp[i][j] = max(dp[i][j],self(self, i, j - 1, matrix[i][j]) + 1);
            return dp[i][j];
        };
        for (int i{}; i < matrix.size(); ++i) {
            for (int j{}; j < matrix[0].size(); ++j) {
                res = max(res, dfs(dfs, i, j, -1));
            }
        } 
        return res;
    }
};
