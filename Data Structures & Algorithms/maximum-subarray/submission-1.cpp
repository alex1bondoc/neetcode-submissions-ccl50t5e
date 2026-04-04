class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int s{};
        int res{nums[0]};
        for (int num : nums) {
            if (s < 0) {
                s = 0;
            }
            s += num;
            res = std::max(s, res);
        }
        return res;
    }
};
