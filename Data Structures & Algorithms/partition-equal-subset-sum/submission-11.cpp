class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum{accumulate(nums.begin(), nums.end(), 0)};
        if (sum % 2) return false;
        sum /= 2;
        vector<int> dp(sum + 1);
        dp[0] = 1;
        for (int i{0}; i < nums.size(); ++i) {
            for (int j{sum}; j >= 0; --j) {
                if (j - nums[i] >= 0)
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
        return dp[sum];
    }
};
