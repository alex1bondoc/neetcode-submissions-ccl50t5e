class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n{static_cast<int>(coins.size())};
        vector<vector<int>> dp(amount + 1, vector<int> (n + 1));
        sort(coins.begin(), coins.end());
        dp[0][0] = 1;
        for (int i{}; i <= n; ++i) {
            dp[0][i] = 1;
        }
        for (int i{1}; i <= n; ++i) {
            for (int a{1}; a <= amount; ++a) {
                if (a - coins[i - 1] >= 0) {
                    dp[a][i] = dp[a - coins[i - 1]][i];
                    
                }
                dp[a][i] += dp[a][i - 1];
            }
        }
        // for (int i{}; i <= amount; ++i, cout << std::endl) {
        //     for (int j{}; j <= n; ++j) {
        //         std::cout << dp[i][j] << " ";
        //     }
        // }
        return dp[amount][n];
    }
};
