class Solution {
public:
    int jump(vector<int>& nums) {
        int n{static_cast<int>(nums.size())};
        int res{};
        int left{};
        int right{};
        while (right < n - 1) {
            int far{};
            for (int i{left}; i <= right; ++i) {
                far = max(far, i + nums[i]);
            }
            res++;
            left = right + 1;
            right = far;
        }
        return res;
    }
};
