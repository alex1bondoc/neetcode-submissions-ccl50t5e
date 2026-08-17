class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n{static_cast<int>(nums.size())};
        int s{accumulate(nums.begin(), nums.end(), 0)};
        if (target > s || target < -s) return 0;
        unordered_map<int, int> dp;
        dp[0] = 1;
        for (const auto& num : nums) {
            unordered_map<int, int> dp1;
            for (const auto& [sum, count] : dp) {
                dp1[sum + num] += count;
                dp1[sum - num] += count;
            }
            dp = dp1;
        }
        return dp[target];
    }
};
