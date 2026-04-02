class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMin = 1;
        int curMax = 1;
        int res = nums[0];
        for (int i{0}; i< nums.size(); ++i) {
            int tmp = curMax * nums[i];
            curMax = std::max(std::max(nums[i] * curMax, nums[i] * curMin), nums[i]);
            curMin = std::min(std::min(nums[i], tmp), nums[i] * curMin);
            res = std::max(res, curMax);
        }
        return res;
    }
    
};
