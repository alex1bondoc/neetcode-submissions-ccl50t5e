class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum{accumulate(nums.begin(), nums.end(), 0)};
        if (sum % 2) return false;
        sum /= 2;
        vector<int> dp(sum + 1);
        dp[0] = 1;
        for (int i{0}; i < sum; ++i) {
            for (int j{}; j < nums.size(); ++j) {
                if (i + nums[j] > sum) continue;
                dp[i + nums[j]] = dp[i];
            }
        }
        return dp[sum];
    }
};
