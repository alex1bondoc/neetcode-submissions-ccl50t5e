class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMin = 1;
        int curMax = 1;
        int res = nums[0];
        for (int i{0}; i < nums.size(); ++i) {
            int num = nums[i];
            int tmp = curMax * num;
            curMax = std::max(std::max(tmp, curMin * num), num);
            curMin = std::min(std::min(tmp, curMin * num), num);
            res = std::max(res, curMax);
        }
        return res;
    }
    
};
