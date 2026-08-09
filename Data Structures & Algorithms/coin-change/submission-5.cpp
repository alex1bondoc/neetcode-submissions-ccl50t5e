class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int maxi{*max_element(coins.begin(), coins.end())};
        int n{static_cast<int>(coins.size())};
        vector<int> dp(amount + 1);
        for(int i{amount - 1}; i >= 0; --i) {
            dp[i] = 1 << 30;
            for(int j{}; j < n; ++j) {
                if (i + coins[j] > amount) continue;
                dp[i] = min(dp[i], dp[i + coins[j]] + 1);
            }
        }
        return dp[0] == 1 << 30 ? -1 : dp[0];
    }
};
