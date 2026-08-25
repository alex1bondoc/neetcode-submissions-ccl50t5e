class Solution {
public:
    int jump(vector<int>& nums) {
        int n{static_cast<int>(nums.size())};
        int res{};
        int left{};
        int right{};
        while (right < n - 1) {
            if (left + nums[left] > right) {
                res++;
                right = left + nums[left];
            }
            left ++;
        }
        return res;
    }
};
