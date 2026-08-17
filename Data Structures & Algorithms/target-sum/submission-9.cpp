class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n{static_cast<int>(nums.size())};
        int s{accumulate(nums.begin(), nums.end(), 0)};
        vector<vector<int>> dp(2 * s + 1, vector<int> (n + 1, -1));
        auto back = [&](auto self, int i, int sum) {
            if (i == n) {

                if (sum == target) dp[sum + s][i] = 1;
                else dp[sum + s][i] = 0;
                return dp[sum + s][i];
            }
            if (dp[sum + s][i] != -1) return dp[sum + s][i];
            dp[sum + s][i] = self(self, i + 1, sum - nums[i]) + self(self, i + 1, sum + nums[i]);
            return dp[sum + s][i];
        };
        
        return back(back, 0, 0);
    }
};
