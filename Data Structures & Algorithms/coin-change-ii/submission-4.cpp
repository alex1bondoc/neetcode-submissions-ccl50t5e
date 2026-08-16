class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n{static_cast<int>(coins.size())};
        sort(coins.begin(), coins.end());
        vector<vector<int>> dp(n + 1, vector<int> (amount + 1, 0));
        for (int i{}; i <= n; ++i) {
            dp[i][0] = 1;
        }
        for (int i{n - 1}; i >= 0; --i) {
            for (int a{}; a <= amount; ++a) {
                if (a >= coins[i]) {
                    dp[i][a] = dp[i + 1][a];
                    dp[i][a] += dp[i][ a - coins[i]];
                }
            }
        }
        return dp[0][amount];
    }
};
