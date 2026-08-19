class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n{static_cast<int>(nums.size())};
        vector<int> newNums(n + 2, 1);
        for (int i{}; i < n; ++i) {
            newNums[i + 1] = nums[i];
        }
        nums = newNums;
        vector<vector<int>> dp(n + 2, vector<int> (n + 2));
        
        for (int l{n}; l >= 1; --l) {
            for (int r{l}; r <= n; ++r) {
                for (int i{l}; i <= r; ++i) {
                    int coins{nums[i] * nums[l - 1] * nums[r + 1] + dp[l][i - 1] + dp[i + 1][r]};
                    dp[l][r] = max(dp[l][r], coins);
                }
            }
        }
        return dp[1][n];
    }
};
