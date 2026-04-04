class Solution {
public:
    bool canJump(vector<int>& nums) {
        int end = nums.size() - 1;
        for (int i = end - 1;i >= 0; --i) {
            if (i + nums[i] >= end) {
                end = i;
            }
        }
        return end == 0;
    }
};
