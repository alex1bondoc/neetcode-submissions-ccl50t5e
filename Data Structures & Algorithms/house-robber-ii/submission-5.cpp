class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> dp1(n + 2, 0);
        std::vector<int> dp2(n + 1, 0);
        for (int i{n - 1}; i >= 1; --i) {
            dp1[i] = std::max(nums[i] + dp1[i + 2], dp1[i + 1]);
        }
        for (int i{n - 2}; i >= 0; --i) {
            dp2[i] = std::max(nums[i] + dp2[i + 2], dp2[i + 1]);
        }
        return std::max(nums[0], std::max(dp1[1], dp2[0]));
    }
};
