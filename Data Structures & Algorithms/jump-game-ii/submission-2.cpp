class Solution {
public:
    int jump(vector<int>& nums) {
        std::vector<int> dp(nums.size() + 1, 1e9);
        dp[nums.size() - 1] = 0;
        for (int i = nums.size() - 2; i >= 0; --i) {
            int res = 1e9;
            for (int j = 1; j <= nums[i] && i + j < nums.size(); ++j) {
                res = std::min(res, 1 + dp[i + j]);
            }
            dp[i] = res;
        }
        return dp[0] == 1e9 ? -1 : dp[0];
    }
};
