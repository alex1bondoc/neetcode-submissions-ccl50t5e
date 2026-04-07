class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        auto dp = [&](auto&& dp, int i, int sum) {
            if (i == nums.size()){
                if (sum == target) return 1;
                return 0;
            } 
            return dp(dp, i + 1, sum + nums[i]) + dp(dp, i + 1, sum - nums[i]);
        };
        return dp(dp, 0, 0);
    }
};
