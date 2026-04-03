class Solution {
private: 
public:
    int coinChange(vector<int>& coins, int amount) {
        std::vector<int> dp(amount + 1, 1e9);
        dp[amount] = 0;
        for(int i{amount}; i> 0; --i) {
            for (auto& coin : coins) {
                if (i - coin >=0) {
                    dp[i - coin] = std::min(dp[i - coin], dp[i] + 1);
                }
            }
        }
        if (dp[0] == 1e9) return -1;
        return dp[0];
    }
};