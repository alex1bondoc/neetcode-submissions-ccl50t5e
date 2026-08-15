class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n{static_cast<int>(prices.size())};
        vector<vector<int>> dp(2, vector<int> (n + 2, -1));
        dp[1][n] = dp[0][n] = 0;
        dp[1][n + 1] = dp[0][n + 1] = 0;
        for (int i{n - 1}; i >= 0; --i) {
            dp[0][i] = max(dp[0][i + 1], dp[1][i + 1] - prices[i]);
            dp[1][i] = max(dp[1][i + 1], dp[0][i + 2] + prices[i]);
        }
        return dp[0][0];
    }
};
