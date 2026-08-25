class Solution {
public:
    int jump(vector<int>& nums) {
        int n{static_cast<int>(nums.size())};
        int res{};
        int farthest{};
        int left{};
        while (farthest < n - 1) {
            int right{};
            for (int l{left}; l <= farthest; ++l) {
                right = max(right, l + nums[l]);
            }
            res ++;
            left++;
            farthest = right;
        }
        return res;
    }
};
