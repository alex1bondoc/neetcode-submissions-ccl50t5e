class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n{static_cast<int>(nums.size())};
        int s{accumulate(nums.begin(), nums.end(), 0)};
        if (target > s || target < -s) return 0;
        vector<vector<int>> dp(2 * s + 1, vector<int> (n + 1));
        dp[s][0] = 1;
        for (int i{1}; i <= n; ++i) {
            for (int j{}; j <= 2 * s; ++j) {
                dp[j][i] = 0;
                if (j - nums[i - 1] >= 0) dp[j][i] += dp[j - nums[i - 1]][i - 1];
                if (j + nums[i - 1] <= 2 * s) dp[j][i] += dp[j + nums[i - 1]][i - 1];
            }
        }
        return dp[target + s][n];
    }
};
