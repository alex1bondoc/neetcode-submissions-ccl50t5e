class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res{nums[0]};
        int curMax{1}, curMin{1};
        for (int n : nums) {
            int tmp{curMax * n};
            curMax = max(max(n, curMax * n), curMin * n);
            curMin = min(min(n, curMin * n), tmp);
            res = max(curMax, res);
        }
        return res;
    }
};
